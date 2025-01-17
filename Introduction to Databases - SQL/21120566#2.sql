﻿DROP DATABASE QLDT
GO

CREATE DATABASE QLDT
GO
USE QLDT
GO

CREATE TABLE GIAOVIEN (
    MAGV CHAR(3) NOT NULL,
    HOTEN NVARCHAR(50) NOT NULL,
    LUONG FLOAT NOT NULL,
    PHAI NVARCHAR(10) NOT NULL,
    NGAYSINH DATE NOT NULL,
    DIACHI NVARCHAR(100) NOT NULL,
    GVQLCM CHAR(3),
    MABM NVARCHAR(4) NOT NULL,
	PRIMARY KEY (MAGV)
);
CREATE TABLE GV_DT (
    MAGV CHAR(3) NOT NULL,
    DIENTHOAI CHAR(10) NOT NULL,
	PRIMARY KEY (MAGV, DIENTHOAI)
);
CREATE TABLE BOMON (
    MABM NVARCHAR(4) NOT NULL,
    TENBM NVARCHAR(50) NOT NULL,
    PHONG CHAR(10) NOT NULL,
    DIENTHOAI CHAR(10) NOT NULL,
    TRUONGBM CHAR(3),
    MAKHOA CHAR(4) NOT NULL,
    NGAYNHANCHUC DATE,
	PRIMARY KEY (MABM)
);
CREATE TABLE KHOA (
    MAKHOA CHAR(4) NOT NULL,
    TENKHOA NVARCHAR(50) NOT NULL,
    NAMTL INT NOT NULL,
    PHONG CHAR(10) NOT NULL,
    DIENTHOAI CHAR(10) NOT NULL,
    TRUONGKHOA CHAR(3) NOT NULL,
    NGAYNHANCHUC DATE NOT NULL,
	PRIMARY KEY (MAKHOA)
);
CREATE TABLE DETAI (
    MADT CHAR(3) NOT NULL,
    TENDT NVARCHAR(100) NOT NULL,
    KINHPHI FLOAT NOT NULL,
    CAPQL VARCHAR(10) NOT NULL,
    NGAYBD DATE NOT NULL,
    NGAYKT DATE NOT NULL,
    MACD NVARCHAR(4) NOT NULL,
    GVCNDT CHAR(3) NOT NULL,
	PRIMARY KEY (MADT)
);
CREATE TABLE THAMGIADT (
    MAGV CHAR(3) NOT NULL,
    MADT CHAR(3) NOT NULL,
    STT INT NOT NULL,
    PHUCAP FLOAT NOT NULL,
    KETQUA VARCHAR(50),
	PRIMARY KEY (MADT, MAGV, STT)
);
CREATE TABLE CHUDE (
    MACD NVARCHAR(4) NOT NULL,
    TENCD NVARCHAR(50) NOT NULL,
	PRIMARY KEY (MACD)
);
CREATE TABLE CONGVIEC (
    MADT CHAR(3) NOT NULL,
    SOTT INT NOT NULL,
    TENCV NVARCHAR(100) NOT NULL,
    NGAYBD DATE NOT NULL,
    NGAYKT DATE NOT NULL,
    PRIMARY KEY (MADT, SOTT),
);
CREATE TABLE NGUOI_THAN (
    MAGV CHAR(3) NOT NULL,
    TEN NVARCHAR(50) NOT NULL,
    NGSINH DATE NOT NULL,
    PHAI NVARCHAR(4) NOT NULL,
    PRIMARY KEY (MAGV, TEN),
);


INSERT INTO GIAOVIEN (MAGV, HOTEN, LUONG, PHAI, NGAYSINH, DIACHI, GVQLCM, MABM)
VALUES 
('001', N'Nguyễn Hoài An', 2000.0, 'Nam', '1973-02-15', N'25/3 Lạc Long Quân, Q.10, TP HCM', NULL, 'MMT'),
('002', N'Trần Trà Hương', 2500.0, 'Nữ', '1960-06-20', N'125 Trần Hưng Đạo, Q.1, TP HCM', '002', 'HTTT'),
('003', N'Nguyễn Ngọc Ánh', 2200.0, 'Nữ', '1975-05-11', N'12/21 Võ Văn Ngân Thủ Đúc, TP HCM', NULL, 'HTTT'),
('004', N'Trương Nam Sơn', 2300.0, 'Nam', '1959-06-20', N'215 Lý Thường Kiệt, TP Biên Hòa', NULL, N'VLĐT'),
('005', N'Lý Hoàng Hà', 2500.0, 'Nam', '1954-10-23', N'22/5 Nguyễn Xí, Q.Bình Thạnh, TP HCM', '004', 'VS'),
('006', N'Trần Bạch Tuyết', 1500.0, 'Nữ', '1980-05-20', N'127 Hùng Vương, TP Mỹ Tho', NULL, 'HPT'),
('007', N'Nguyễn An Trung', 2100.0, 'Nam', '1976-06-05', N'234 3/2, TP Biên Hòa', '007', 'HPT'),
('008', N'Trần Trung Hiếu', 1800.0, 'Nam', '1977-08-06', N'22/11 Lý Thường Kiệt, TP Mỹ Tho', '001', 'MMT'),
('009', N'Trần Hoài Nam', 2000.0, 'Nam', '1975-11-22', N'234 Trần Não, An Phú, TP HCM', NULL, 'HPT'),
('010', N'Phạm Nam Thanh', 1500.0, 'Nam', '1980-12-12', N'221 Hùng Vương, Q.5, TP HCM', '007', 'HPT');

INSERT INTO GV_DT (MAGV, DIENTHOAI)
VALUES 
    ('001', '0838912112'),
    ('001', '0903123123'),
    ('002', '0913454545'),
    ('003', '0838121212'),
    ('003', '0903656565'),
    ('003', '0937125125'),
    ('006', '0937888888'),
    ('008', '0653717171'),
    ('008', '0913232323');

INSERT INTO BOMON (MABM, TENBM, PHONG, DIENTHOAI, TRUONGBM, MAKHOA, NGAYNHANCHUC)
VALUES 
    ('CNTT', N'Công nghệ tri thức', 'B15', '0838126126', NULL, 'CNTT', NULL),
    ('HHC', N'Hóa hữu cơ', 'B44', '838222222', NULL, 'HH', NULL),
    ('HL', N'Hóa lý', 'B42', '0838878787', NULL, 'HH', '2007-10-15'),
    ('HPT', N'Hóa phân tích', 'B43', '0838777777', '007', 'HH', '2004-09-20'),
    ('HTTT', N'Hệ thống thông tin', 'B13', '0838125125', '002', 'CNTT', '2005-05-15'),
    ('MMT', N'Mạng máy tính', 'B16', '0838676767', '001', 'CNTT', '2006-02-18'),
    ('SH', N'Sinh hóa', 'B33', '0838898989', NULL, 'SH', '2007-01-01'),
    (N'VLĐT', N'Vật lí điện tử', 'B23', '0838234234', NULL, 'VL', NULL),
    (N'VLƯD', N'Vật lý ứng dụng', 'B24', '08384S4S4S', '005', 'VL', NULL),
    ('VS', N'Vi sinh', 'B32', '0838909090', '004', 'SH', NULL);

INSERT INTO KHOA (MAKHOA, TENKHOA, NAMTL, PHONG, DIENTHOAI, TRUONGKHOA, NGAYNHANCHUC)
VALUES 
    ('CNTT', N'Công nghệ thông tin', 1995, 'B11', '0838123456', '002', '2005-02-20'),
    ('HH', N'Hóa học', 1980, 'B41', '0838456456', '007', '2001-10-15'),
    ('SH', N'Sinh học', 1980, 'B31', '0838454545', '004', '2000-10-11'),
    ('VL', N'Vật lý', 1976, 'B21', '0838223223', '005', '2003-09-18');

INSERT INTO DETAI (MADT, TENDT, KINHPHI, CAPQL, NGAYBD, NGAYKT, MACD, GVCNDT)
VALUES 
    ('001', N'HTTT quản lí các trường ĐH', 20.0, N'ĐHQG', '2007-10-20', '2008-10-20', 'QLGD', '002'),
    ('002', N'HTTT quản lý giáo vụ cho một Khoa', 20.0, N'Trường', '2000-10-12', '2001-10-12', 'QLGD', '002'),
    ('003', N'Nghiên cứu chế tạo sợi Nanô Platin', 300.0, N'ĐHQG', '2008-05-15', '2010-05-15', 'NCPT', '005'),
    ('004', N'Tạo vật liệu sinh học bằng màng ối người', 100.0, N'Nhà nước', '2007-01-01', '2009-12-31', 'NCPT', '004'),
    ('005', N'Ứng dụng hóa học xanh', 200.0, N'Trường', '2003-10-10', '2004-12-10', 'ƯDCN', '007'),
    ('006', N'Nghiên cứu tế bào gốc', 4000.0, N'Nhà nước', '2006-10-20', '2009-10-20', 'NCPT', '004'),
    ('007', N'HTTT quản lí thư viện ở các trường ĐH', 20.0, N'Trường', '2009-05-10', '2010-05-10', 'QLGD', '001');

INSERT INTO CHUDE (MACD, TENCD)
VALUES 
    (N'NCPT', N'Nghiên cứu phát triển'),
    (N'QLGD', N'Quản lý giáo dục'),
    (N'ƯDCN', N'Ứng dụng công nghệ');

INSERT INTO CONGVIEC (MADT, SOTT, TENCV, NGAYBD, NGAYKT)
VALUES 
    ('001', 1, 'Khởi tạo và Lập kế hoạch', '2007-10-20', '2008-12-20'),
    ('001', 2, 'Xác định yêu cầu', '2008-12-21', '2008-03-21'),
    ('001', 3, 'Phân tích hệ thống', '2008-03-22', '2008-05-22'),
    ('001', 4, 'Thiết kế hệ thống', '2008-05-23', '2008-06-23'),
    ('001', 5, 'Cài đặt thử nghiệm', '2008-06-24', '2008-10-20'),
    ('002', 1, 'Khởi tạo và Lập kế hoạch', '2009-05-10', '2009-07-10'),
    ('002', 2, 'Xác định yêu cầu', '2009-07-11', '2009-10-11'),
    ('002', 3, 'Phân tích hệ thống', '2009-10-12', '2009-12-20'),
    ('002', 4, 'Thiết kế hệ thống', '2009-12-21', '2010-03-22'),
    ('002', 5, 'Cài đặt thử nghiệm', '2010-03-23', '2010-05-10'),
    ('006', 1, 'Lấy mẫu', '2006-10-20', '2007-02-20'),
    ('006', 2, 'Nuôi cấy', '2007-02-21', '2008-08-21');



INSERT INTO THAMGIADT (MAGV, MADT, STT, PHUCAP, KETQUA)
VALUES 
    ('001', '002', 1, 2.0, NULL),
    ('001', '002', 2, 2.0, NULL),
    ('002', '001', 4, 1.0, 'Đạt'),
    ('003', '001', 1, 0.0, 'Đạt'),
    ('003', '001', 2, 1.0, 'Đạt'),
    ('003', '001', 4, 0.0, 'Đạt'),
    ('003', '002', 2, 0.0, NULL),
    ('004', '006', 1, 1.0, 'Đạt'),
    ('004', '006', 2, 1.0, 'Đạt'),
    ('006', '006', 2, 0.0, NULL),
    ('009', '002', 3, 0.0, NULL),
    ('009', '002', 4, 0.0, NULL);

INSERT INTO NGUOI_THAN (MAGV, TEN, NGSINH, PHAI)
VALUES 
    ('001', 'Hùng', '1990-01-14', 'Nam'),
    ('001', 'Thuỷ', '1994-12-08', 'Nữ'),
    ('003', 'Hà', '1998-09-03', 'Nữ'),
    ('003', 'Thu', '1998-09-03', 'Nữ'),
    ('007', 'Mai', '2003-03-26', 'Nữ'),
    ('007', 'Vy', '2000-02-14', 'Nữ'),
    ('008', 'Nam', '1991-05-06', 'Nam'),
    ('009', 'An', '1996-08-19', 'Nữ'),
    ('010', 'Nguyệt', '1991-05-06', 'Nữ'),
    ('010', 'Hà', '1996-08-19', 'Nữ'),
    ('010', 'Vy', '2006-01-14', 'Nữ');


ALTER TABLE BOMON ADD
	FOREIGN KEY (TRUONGBM) REFERENCES GIAOVIEN(MAGV),
	FOREIGN KEY (MAKHOA) REFERENCES KHOA(MAKHOA);

ALTER TABLE GIAOVIEN ADD
	FOREIGN KEY (GVQLCM) REFERENCES GIAOVIEN(MAGV),
    FOREIGN KEY (MABM) REFERENCES BOMON(MABM);

ALTER TABLE DETAI WITH NOCHECK ADD
    FOREIGN KEY (GVCNDT) REFERENCES GIAOVIEN(MAGV),
	FOREIGN KEY (MACD) REFERENCES CHUDE(MACD);
	
ALTER TABLE CONGVIEC ADD
    FOREIGN KEY (MADT) REFERENCES DETAI(MADT);

ALTER TABLE GV_DT ADD
    FOREIGN KEY (MAGV) REFERENCES GIAOVIEN(MAGV);

ALTER TABLE NGUOI_THAN ADD
    FOREIGN KEY (MAGV) REFERENCES GIAOVIEN(MAGV);

ALTER TABLE KHOA ADD
    FOREIGN KEY (TRUONGKHOA) REFERENCES GIAOVIEN(MAGV);

ALTER TABLE THAMGIADT ADD
    FOREIGN KEY (MAGV) REFERENCES GIAOVIEN(MAGV);
--	FOREIGN KEY (MADT) REFERENCES CONGVIEC(MADT);



SELECT COUNT(*), SUM(LUONG) FROM GIAOVIEN

SELECT * FROM GIAOVIEN
SELECT gv.MABM, AVG(gv.LUONG) FROM GIAOVIEN gv INNER JOIN BOMON bm ON gv.MABM = bm.MABM
GROUP BY gv.MABM

SELECT * FROM DETAI
SELECT cd.TENCD, COUNT(dt.MACD) FROM CHUDE cd INNER JOIN DETAI dt ON cd.MACD = dt.MACD
GROUP BY cd.TENCD