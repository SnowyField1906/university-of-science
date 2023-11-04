-- Ho Ten: Nguyen Huu Thuan
-- MSSV: 21120566
-- Ma Lop: 21_5
-- De: 03

USE QLKhoaLuan

-- Cau 1 :
SELECT DISTINCT N.TenNganh
FROM Nganh N, DeTai_TN DTTN
WHERE DTTN.MaNganh = N.MaNganh AND NOT EXISTS (
    SELECT G.MaGV
    FROM GiaoVien G
    WHERE G.MaNganh = DTTN.MaNganh AND G.MaGV NOT IN (
        SELECT D1.GVHD1 FROM DeTai_TN D1
        UNION
        SELECT D2.GVHD2 FROM DeTai_TN D2
    )
)

-- Cau 2:
CREATE FUNCTION SoDeTaiHuongDan (@MaGV varchar(5))
RETURNS INT
AS
BEGIN
    DECLARE @Count INT;

    SELECT @Count = COUNT(*) FROM DeTai_TN
    WHERE GVHD1 = @MaGV OR GVHD2 = @MaGV;
    RETURN @Count;
END;
-- test
SELECT MaGV, dbo.SoDeTaiHuongDan(MaGV) AS SoDeTaiHuongDan FROM GiaoVien;

-- Cau3:
CREATE PROCEDURE TopGVHD_Nam(@Nam INT)
AS
BEGIN
    SELECT G.MaGV, G.HoTen, N.TenNganh, COUNT(DT.MaDT) AS SoLuongDeTai FROM GiaoVien G
    JOIN DeTai_TN DT ON G.MaGV = DT.GVHD1 OR G.MaGV = DT.GVHD2
    JOIN Nganh N ON G.MaNganh = N.MaNganh
    WHERE YEAR(DT.TuNgay) = @Nam OR YEAR(DT.DenNgay) = @Nam 
    GROUP BY G.MaGV, G.HoTen, N.TenNganh
    HAVING COUNT(DT.MaDT) > 0
    ORDER BY COUNT(DT.MaDT) DESC;
END;
-- test
EXECUTE TopGVHD_Nam 2021;

-- Cau 4:
CREATE PROCEDURE ThemLichBaoVe @Nam INT, @Dot_BV INT, @MaNganh VARCHAR(5), @MaSV VARCHAR(5), @MaDT VARCHAR(5)
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM LichBaoVe
        WHERE Nam = @Nam AND MaSV = @MaSV AND MaDT = @MaDT
    )
    BEGIN
        RETURN
    END

    IF (
        SELECT COUNT(*)
        FROM LichBaoVe
        WHERE Nam = @Nam AND Dot_BV = @Dot_BV AND MaDT = @MaDT
    ) >= 6
    BEGIN
        RETURN
    END

    INSERT INTO LichBaoVe (Nam, Dot_BV, MaNganh, MaSV, MaDT)
    VALUES (@Nam, @Dot_BV, @MaNganh, @MaSV, @MaDT)
END;
-- test
EXECUTE ThemLichBaoVe @Nam = 2021, @Dot_BV = 2, @MaNganh = 'HTTT', @MaSV = 'SV03', @MaDT = 'DT02';
