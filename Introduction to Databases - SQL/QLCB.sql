-- Q1. Cho biết mã số, tên phi công, địa chỉ, điện thoại của các phi công đã từng lái máy bay loại B747.
SELECT NV.MANV, NV.TEN, NV.DCHI, NV.DTHOAI
FROM NHANVIEN NV
JOIN KHANANG KN ON NV.MANV = KN.MANV
WHERE NV.LOAINV = 1 AND KN.MALOAI = 'B747';

-- Q2. Cho biết mã số và ngày đi của các chuyến bay xuất phát từ sân bay DCA trong khoảng thời gian từ 14 giờ đến 18 giờ.
SELECT MACB, NGAYDI
FROM LICHBAY
WHERE SBDI = 'DCA' AND GIODI BETWEEN '14:00' AND '18:00';

-- Q3. Cho biết tên những nhân viên được phân công trên chuyến bay có mã số 100 xuất phát tại sân bay SLC. Các dòng dữ liệu xuất ra không được phép trùng lắp.
SELECT DISTINCT NV.TEN
FROM NHANVIEN NV
JOIN PHANCONG PC ON NV.MANV = PC.MANV
WHERE PC.MACB = '100' AND PC.NGAYDI IN (SELECT NGAYDI FROM CHUYENBAY WHERE SBDI = 'SLC');

-- Q4. Cho biết mã loại và số hiệu máy bay đã từng xuất phát tại sân bay MIA. Các dòng dữ liệu xuất ra không được phép trùng lắp.
SELECT DISTINCT MALOAI, SOHIEU
FROM LICHBAY
WHERE MACB IN (SELECT MACB FROM CHUYENBAY WHERE SBDI = 'MIA');

-- Q5. Cho biết mã chuyến bay, ngày đi, cùng với tên, địa chỉ, điện thoại của tất cả các hành khách đi trên chuyến bay đó. Sắp xếp theo thứ tự tăng dần của mã chuyến bay và theo ngày đi giảm dần.
SELECT CB.MACB, LB.NGAYDI, KH.TEN, KH.DCHI, KH.DTHOAI
FROM DATCHO DC
JOIN KHACHHANG KH ON DC.MAKH = KH.MAKH
JOIN CHUYENBAY CB ON DC.MACB = CB.MACB
JOIN LICHBAY LB ON DC.MACB = LB.MACB AND DC.NGAYDI = LB.NGAYDI
ORDER BY CB.MACB ASC, LB.NGAYDI DESC;

-- Q6. Cho biết mã chuyến bay, ngày đi, cùng với tên, địa chỉ, điện thoại của tất cả những nhân viên được phân công trong chuyến bay đó. Sắp xếp theo thứ tự tăng dần của mã chuyến bay và theo ngày đi giảm dần.
SELECT CB.MACB, LB.NGAYDI, NV.MANV, NV.TEN, NV.DCHI, NV.DTHOAI
FROM PHANCONG PC
JOIN NHANVIEN NV ON PC.MANV = NV.MANV
JOIN CHUYENBAY CB ON PC.MACB = CB.MACB
JOIN LICHBAY LB ON PC.MACB = LB.MACB AND PC.NGAYDI = LB.NGAYDI
ORDER BY CB.MACB ASC, LB.NGAYDI DESC;

-- Q7. Cho biết mã chuyến bay, ngày đi, mã số và tên của những phi công được phân công vào chuyến bay hạ cánh xuống sân bay ORD.
SELECT CB.MACB, LB.NGAYDI, NV.MANV, NV.TEN
FROM PHANCONG PC
JOIN NHANVIEN NV ON PC.MANV = NV.MANV
JOIN CHUYENBAY CB ON PC.MACB = CB.MACB
JOIN LICHBAY LB ON PC.MACB = LB.MACB AND PC.NGAYDI = LB.NGAYDI
WHERE CB.SBDEN = 'ORD' AND NV.LOAINV = 1;

-- Q8. Cho biết các chuyến bay (mã số chuyến bay, ngày đi và tên của phi công) trong đó phi công có mã 1001 được phân công lái.
SELECT CB.MACB, LB.NGAYDI, NV.TEN
FROM PHANCONG PC
JOIN NHANVIEN NV ON PC.MANV = NV.MANV
JOIN CHUYENBAY CB ON PC.MACB = CB.MACB
JOIN LICHBAY LB ON PC.MACB = LB.MACB AND PC.NGAYDI = LB.NGAYDI
WHERE NV.MANV = '1001';

-- Q9. Cho biết thông tin (mã chuyến bay, sân bay đi, giờ đi, giờ đến, ngày đi) của những chuyến bay hạ cánh xuống DEN. Các chuyến bay được liệt kê theo ngày đi giảm dần và sân bay xuất phát (SBDI) tăng dần .
SELECT CB.MACB, CB.SBDI, CB.GIODI, CB.GIODEN, LB.NGAYDI
FROM CHUYENBAY CB
JOIN LICHBAY LB ON CB.MACB = LB.MACB
WHERE CB.SBDEN = 'DEN'
ORDER BY LB.NGAYDI DESC, CB.SBDI ASC;

-- Q10. Với mỗi phi công, cho biết hãng sản xuất và mã loại máy bay mà phi công này có khả năng bay được. Xuất ra tên phi công, hãng sản xuất và mã loại máy bay.
SELECT NV.TEN, LMB.HANGSX, LMB.MALOAI
FROM NHANVIEN NV
JOIN KHANANG KN ON NV.MANV = KN.MANV
JOIN LOAIMB LMB ON KN.MALOAI = LMB.MALOAI
WHERE NV.LOAINV = 1;

-- Q11. Cho biết mã phi công, tên phi công đã lái máy bay trong chuyến bay mã số 100 vào ngày 11/01/2000.
SELECT NV.MANV, NV.TEN
FROM NHANVIEN NV
JOIN PHANCONG PC ON NV.MANV = PC.MANV
WHERE PC.MACB = '100' AND PC.NGAYDI = '11/01/2000';

-- Q12. Cho biết mã chuyến bay, mã nhân viên, tên nhân viên được phân công vào chuyến bay xuất phát ngày 10/31/2000 tại sân bay MIA vào lúc 20:30
SELECT PC.MACB, NV.MANV, NV.TEN
FROM PHANCONG PC
JOIN NHANVIEN NV ON PC.MANV = NV.MANV
JOIN CHUYENBAY CB ON PC.MACB = CB.MACB
WHERE PC.NGAYDI = '10/31/2000' AND CB.SBDI = 'MIA' AND CB.GIODI = '20:30';

-- Q13. Cho biết thông tin về chuyến bay (mã chuyến bay, số hiệu, mã loại, hãng sản xuất) mà phi công "Quang" đã lái.
SELECT CB.MACB, MB.SOHIEU, MB.MALOAI, LMB.HANGSX
FROM NHANVIEN NV
JOIN PHANCONG PC ON NV.MANV = PC.MANV
JOIN CHUYENBAY CB ON PC.MACB = CB.MACB
JOIN LICHBAY LB ON PC.MACB = LB.MACB AND PC.NGAYDI = LB.NGAYDI
JOIN MAYBAY MB ON LB.SOHIEU = MB.SOHIEU
JOIN LOAIMB LMB ON MB.MALOAI = LMB.MALOAI
WHERE NV.TEN = 'Quang';

-- Q14. Cho biết tên của những phi công chưa được phân công lái chuyến bay nào.
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV = 1 AND NV.MANV NOT IN (SELECT MANV FROM PHANCONG);

-- Q15. Cho biết tên khách hàng đã đi chuyến bay trên máy bay của hãng "Boeing".
SELECT DISTINCT KH.TEN
FROM KHACHHANG KH
JOIN DATCHO DC ON KH.MAKH = DC.MAKH
JOIN LICHBAY LB ON DC.MACB = LB.MACB AND DC.NGAYDI = LB.NGAYDI
JOIN MAYBAY MB ON LB.SOHIEU = MB.SOHIEU
JOIN LOAIMB LMB ON MB.MALOAI = LMB.MALOAI
WHERE LMB.HANGSX = 'Boeing';

-- Q16. Cho biết mã các chuyến bay chỉ bay với máy bay số hiệu 10 và mã loại B747.
SELECT CB.MACB
FROM CHUYENBAY CB
JOIN LICHBAY LB ON CB.MACB = LB.MACB
WHERE LB.SOHIEU = 10 AND LB.MALOAI = 'B747';