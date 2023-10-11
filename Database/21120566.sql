-- Câu 2: Viết store thực hiện cập nhật ngày kết thúc của dự án. Lưu ý, ngày kết thúc phải sau ngày bắt đầu theo quy định:
create proc sp_CapNhatNGAYKT @MaDT char(5), @NgayKT date, @CapQL nvarchar(20)
as
begin
	if not exists (select MADT from DETAI where MADT = @MaDT)
	begin
		raiserror(N'Không tồn tại', 15, 1)
		return
	end

	if @CapQL = N'Trường'
	begin 
		UPDATE DETAI
		SET NGAYKT = @NgayKT
		WHERE MADT = @MaDT AND DATEDIFF(month, NGAYBD, @NgayKT) BETWEEN 3 AND 6
	end

	else if @CapQL = N'ĐHQG'
	begin 
		UPDATE DETAI
		SET NGAYKT = @NgayKT
		WHERE MADT = @MaDT AND DATEDIFF(month, NGAYBD, @NgayKT) BETWEEN 6 AND 9
	end

	else if @CapQL = N'Nhà nước'
	begin 
		UPDATE DETAI
		SET NGAYKT = @NgayKT
		WHERE MADT = @MaDT AND DATEDIFF(month, NGAYBD, @NgayKT) BETWEEN 12 AND 24
	end
end
go
exec sp_CapNhatNGAYKT '003', '12-15-2008', N'ĐHQG'

-- Câu 3: Viết store thực hiện cập nhật giáo viên quản lý chuyên môn cho 1 giảng viên cụ thể. Lưu ý, GVQLCM phải cùng bộ môn với giảng viên cần cập nhật.
create proc sp_UpdateGVQLCM @magv varchar(5), @gvqlcm varchar(5)
as
begin
	if not exists (select magv from GIANGVIEN where magv = @magv)
	begin
		raiserror(N'magv không tồn tại', 15, 1)
		return
	end
	if not exists (select magv from GIANGVIEN where magv = @gvqlcm)
	begin
		raiserror(N'gvqlcm không tồn tại', 15, 1)
		return
	end
	
	if (select mabm from GIANGVIEN where magv = @magv) = (select mabm from GIANGVIEN where magv = @gvqlcm)
	begin 
		update GIANGVIEN set gvqlcm = @gvqlcm where magv = @magv
		print N'Cập nhật thành công'
	end
	else
		print N'gvqlcm không cùng bộ môn với gv'
end
go 
exec sp_UpdateNgayKT '001', '009'	
go

-- Câu 5: Viết stored đếm số lượng công việc có kết quả “Đạt” của mỗi đề tài
CREATE PROCEDURE sp_DemDat
AS
BEGIN
		select distinct count(*) as SoLuongDat
		from THAMGIADT tgdt 
		WHERE tgdt.KETQUA = N'Đạt'
END
go
exec sp_DemDat
go

-- Câu 6: Viết stored đếm số lượng công việc có kết quả “Không Đạt” của mỗi đề tài
CREATE PROCEDURE sp_DemKhongDat
AS
BEGIN
		select distinct count(*) as SoLuongKhongDat
		from THAMGIADT tgdt
		WHERE tgdt.KETQUA = N'Không đạt'
END
go
exec sp_DemKhongDat

-- Câu 7: Viết stored đếm số lượng công việc có kết quả “NULL” của mỗi đề tài
CREATE PROCEDURE sp_DemNULL
AS
BEGIN
		select distinct count(*) as SoLuongNULL
		from THAMGIADT tgdt
		WHERE tgdt.KETQUA is NULL
END
go
exec sp_DemNULL
