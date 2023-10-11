--Q1. Cho biết họ tên và mức lương của các giáo viên nữ.
SELECT HOTEN, LUONG
FROM GIAOVIEN
WHERE PHAI = N'Nữ';

--Q2. Cho biết họ tên của các giáo viên và lương của họ sau khi tăng 10%.
SELECT HOTEN, LUONG * 1.1 AS LUONGMOI
FROM GIAOVIEN;

--Q3. Cho biết mã của các giáo viên có họ tên bắt đầu là “Nguyễn” và lương trên $2000 hoặc, giáo viên là trưởng bộ môn nhận chức sau năm 1995.
SELECT MAGV
FROM GIAOVIEN
WHERE (HOTEN LIKE N'Nguyễn%' AND LUONG > 2000) OR (MAGV IN (SELECT TRUONGBM FROM BOMON WHERE NGAYNHANCHUC > '1995-01-01'));

--Q4. Cho biết tên những giáo viên khoa Công nghệ thông tin.
SELECT HOTEN
FROM GIAOVIEN
WHERE MABM IN (SELECT MABM FROM BOMON WHERE MAKHOA IN (SELECT MAKHOA FROM KHOA WHERE TENKHOA = N'Công nghệ thông tin'));

--Q5. Cho biết thông tin của bộ môn cùng thông tin giảng viên làm trưởng bộ môn đó.
SELECT BM.*, GV.HOTEN
FROM BOMON BM
JOIN GIAOVIEN GV ON BM.TRUONGBM = GV.MAGV;

--Q6. Với mỗi giáo viên, hãy cho biết thông tin của bộ môn mà họ đang làm việc. 
SELECT GV.MAGV, GV.HOTEN, BM.MABM, BM.TENBM
FROM GIAOVIEN GV
JOIN BOMON BM ON GV.MABM = BM.MABM;

--Q7. Cho biết tên đề tài và giáo viên chủ nhiệm đề tài. 
SELECT DT.TENDT, GV.HOTEN
FROM DETAI DT
JOIN GIAOVIEN GV ON DT.GVCNDT = GV.MAGV;

--Q8. Với mỗi khoa cho biết thông tin trưởng khoa. 
SELECT K.MAKHOA, K.TENKHOA, GV.HOTEN
FROM KHOA K
JOIN GIAOVIEN GV ON K.TRUONGKHOA = GV.MAGV;

--Q9. Cho biết các giáo viên của bộ môn “Vi sinh” có tham gia đề tài 006. 
SELECT GV.HOTEN
FROM GIAOVIEN GV
JOIN THAMGIADT TGD ON GV.MAGV = TGD.MAGV
WHERE TGD.MADT = '006' AND GV.MABM IN (SELECT MABM FROM BOMON WHERE TENBM = N'Vi sinh');

--Q10. Với những đề tài thuộc cấp quản lý “Thành phố”, cho biết mã đề tài, đề tài thuộc về chủ đề nào, họ tên người chủ nghiệm đề tài cùng với ngày sinh và địa chỉ của người ấy.
SELECT DT.MADT, CD.TENCD, GV.HOTEN, GV.NGAYSINH, GV.DIACHI
FROM DETAI DT
JOIN CHUDE CD ON DT.MACD = CD.MACD
JOIN GIAOVIEN GV ON DT.GVCNDT = GV.MAGV
WHERE DT.CAPQL = N'Thành phố';

--Q11. Tìm họ tên của từng giáo viên và người phụ trách chuyên môn trực tiếp của giáo viên đó.
SELECT GV1.HOTEN AS 'GiaoVien', GV2.HOTEN AS 'PhuTrachChuyenMon'
FROM GIAOVIEN GV1
JOIN GIAOVIEN GV2 ON GV1.GVQLCM = GV2.MAGV;

--Q12. Tìm họ tên của những giáo viên được “Nguyễn Thanh Tùng” phụ trách trực tiếp. 
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.GVQLCM = (SELECT MAGV FROM GIAOVIEN WHERE HOTEN = N'Nguyễn Thanh Tùng');

--Q13. Cho biết tên giáo viên là trưởng bộ môn “Hệ thống thông tin”.
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.MABM = (SELECT MABM FROM BOMON WHERE TENBM = N'Hệ thống thông tin') AND GV.MAGV IN (SELECT TRUONGBM FROM BOMON);

--Q14. Cho biết tên người chủ nhiệm đề tài của những đề tài thuộc chủ đề Quản lý giáo dục.
SELECT GV.HOTEN
FROM GIAOVIEN GV
JOIN DETAI DT ON GV.MAGV = DT.GVCNDT
WHERE DT.MACD IN (SELECT MACD FROM CHUDE WHERE TENCD = N'Quản lý giáo dục');

--Q15. Cho biết tên các công việc của đề tài HTTT quản lý các trường ĐH có thời gian bắt đầu trong tháng 3/2008.
SELECT TENCV
FROM CONGVIEC
WHERE MADT = 'HTTT' AND NGAYBD BETWEEN '2008-03-01' AND '2008-03-31';

--Q16. Cho biết tên giáo viên và tên người quản lý chuyên môn của giáo viên đó. 
SELECT GV1.HOTEN AS 'GiaoVien', GV2.HOTEN AS 'PhuTrachChuyenMon'
FROM GIAOVIEN GV1
JOIN GIAOVIEN GV2 ON GV1.GVQLCM = GV2.MAGV;

--Q17. Cho các công việc bắt đầu trong khoảng từ 01/01/2007 đến 01/08/2007. 
SELECT *
FROM CONGVIEC
WHERE NGAYBD BETWEEN '2007-01-01' AND '2007-08-01';

--Q18. Cho biết họ tên các giáo viên cùng bộ môn với giáo viên “Trần Trà Hương”. 
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.MABM = (SELECT MABM FROM GIAOVIEN WHERE HOTEN = N'Trần Trà Hương');

--Q19. Tìm những giáo viên vừa là trưởng bộ môn vừa chủ nhiệm đề tài.
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.MAGV IN (SELECT TRUONGBM FROM BOMON) AND GV.MAGV IN (SELECT GVCNDT FROM DETAI);

--Q20. Cho biết tên những giáo viên vừa là trưởng khoa và vừa là trưởng bộ môn. 
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.MAGV IN (SELECT TRUONGKHOA FROM KHOA) AND GV.MAGV IN (SELECT TRUONGBM FROM BOMON);

--Q21. Cho biết tên những trưởng bộ môn mà vừa chủ nhiệm đề tài.
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.MAGV IN (SELECT TRUONGBM FROM BOMON) AND GV.MAGV IN (SELECT GVCNDT FROM DETAI);

--Q22. Cho biết mã số các trưởng khoa có chủ nhiệm đề tài. 
SELECT K.TRUONGKHOA
FROM KHOA K
WHERE K.TRUONGKHOA IN (SELECT GVCNDT FROM DETAI);

--Q23. Cho biết mã số các giáo viên thuộc bộ môn “HTTT” hoặc có tham gia đề tài mã “001”. 
SELECT MAGV
FROM GIAOVIEN
WHERE MABM IN (SELECT MABM FROM BOMON WHERE TENBM = N'HTTT') OR MAGV IN (SELECT MAGV FROM THAMGIADT WHERE MADT = '001');

--Q24. Cho biết giáo viên làm việc cùng bộ môn với giáo viên 002.
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.MABM = (SELECT MABM FROM GIAOVIEN WHERE MAGV = '002');

--Q25. Tìm những giáo viên là trưởng bộ môn.
SELECT GV.HOTEN
FROM GIAOVIEN GV
WHERE GV.MAGV IN (SELECT TRUONGBM FROM BOMON);

--Q26. Cho biết họ tên và mức lương của các giáo viên.
SELECT HOTEN, LUONG
FROM GIAOVIEN;