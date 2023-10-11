DROP DATABASE QLDL
GO
CREATE DATABASE QLDL
GO
USE QLDL
GO

CREATE TABLE TINH_TP (
    QuocGia VARCHAR(10),
    MaTinhThanh VARCHAR(10),
    TenTT NVARCHAR(30),
    SoDan INT,
    DienTich INT,
    DiemDLUaThichNhat VARCHAR(10),
	PRIMARY KEY (QuocGia, MaTinhThanh)
);

CREATE TABLE QUOCGIA (
    MaQG VARCHAR(10) PRIMARY KEY,
    TenQG NVARCHAR(10),
    ThuDo VARCHAR(30)
);

CREATE TABLE DIEM_DL (
    MaDiaDiem VARCHAR(10) PRIMARY KEY,
    TenDiaDiem NVARCHAR(50),
    TinhTP VARCHAR(10),
    QuocGia VARCHAR(10),
    DacDiem NVARCHAR(100)
);


INSERT INTO TINH_TP VALUES ('QG001', 'TT001', N'Hà Nội', 2500000, 927.39, 'DD001'),
	('QG001', 'TT002', N'Huế', 5344000, 5009.00, 'DD002'),
	('QG002', 'TT001', N'Tokyo', 12084000, 2187.00, NULL),
	('QG002', 'TT002', N'Osaka', 18000000, 221.96, 'DD001');

INSERT INTO QUOCGIA (MaQG, TenQG, ThuDo) VALUES
	('QG001', N'Việt Nam', 'TT001'),
	('QG002', N'Nhật Bản', 'TT003');

INSERT INTO DIEM_DL VALUES
	('DD001', N'Văn Miếu', 'TT001', 'QG001', N'Di tích cổ'),
	('DD002', N'Hoàng lăng', 'TT002', 'QG001', N'Di tích cổ'),
	('DD003', N'Núi Fuji', 'TT001', 'QG002', N'Núi lửa ngưng hoạt động cao nhất'),
	('DD004', N'Minami', 'TT002', 'QG002', N'quê hương của cây cầu Shinsaibashi'),
	('DD005', N'Lâu đài Osaka', 'TT002', 'QG002', N'Chứa bảo tàng thông tin lịch sử của Nhật Bản');


ALTER TABLE TINH_TP ADD FOREIGN KEY (QuocGia) REFERENCES QUOCGIA(MaQG);
ALTER TABLE TINH_TP ADD FOREIGN KEY (MaTinhThanh) REFERENCES DIEM_DL(TinhTP);
ALTER TABLE DIEM_DL ADD FOREIGN KEY (QuocGia) REFERENCES QUOCGIA(MaQG);