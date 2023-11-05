USE [master]
GO
/****** Object:  Database [QLKhoaLuan]    Script Date: 1/6/2023 4:12:56 PM ******/
CREATE DATABASE [QLKhoaLuan]
GO

USE [QLKhoaLuan]
GO
/****** Object:  Table [dbo].[DeTai_TN]    Script Date: 1/6/2023 4:12:56 PM ******/
CREATE TABLE [dbo].[DeTai_TN](
	[MaDT] [varchar](5) NOT NULL,
	[TenDT] [nvarchar](100) NULL,
	[LoaiDT] [varchar](5) NULL,
	[NienKhoa] [int] NULL,
	[TuNgay] [date] NULL,
	[DenNgay] [date] NULL,
	[MaNganh] [varchar](5) NULL,
	[GVHD1] [varchar](5) NULL,
	[GVHD2] [varchar](5) NULL,
	[XepLoai] [nvarchar](50) NULL,
 CONSTRAINT [PK_DeTai_TN] PRIMARY KEY CLUSTERED 
(
	[MaDT] ASC
))
GO
/****** Object:  Table [dbo].[GiaoVien]    Script Date: 1/6/2023 4:12:56 PM ******/
CREATE TABLE [dbo].[GiaoVien](
	[MaGV] [varchar](5) NOT NULL,
	[HoTen] [nvarchar](50) NULL,
	[MaNganh] [varchar](5) NULL,
	[CDKH] [nvarchar](10) NULL,
 CONSTRAINT [PK_GiaoVien] PRIMARY KEY CLUSTERED 
(
	[MaGV] ASC
))
GO
/****** Object:  Table [dbo].[HoiDong]    Script Date: 1/6/2023 4:12:56 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HoiDong](
	[Nam] [int] NOT NULL,
	[Dot_BV] [int] NOT NULL,
	[MaNganh] [varchar](5) NOT NULL,
	[UyVien] [varchar](5) NULL,
	[ThuKy] [varchar](5) NULL,
	[ChuTichHD] [varchar](5) NULL,
	[NgayBV] [datetime] NULL,
 CONSTRAINT [PK_HoiDong] PRIMARY KEY CLUSTERED 
(
	[Nam] ASC,
	[Dot_BV] ASC,
	[MaNganh] ASC
))
GO
/****** Object:  Table [dbo].[LichBaoVe]    Script Date: 1/6/2023 4:12:56 PM ******/

CREATE TABLE [dbo].[LichBaoVe](
	[Nam] [int] NOT NULL,
	[Dot_BV] [int] NOT NULL,
	[MaNganh] [varchar](5) NOT NULL,
	[MaSV] [varchar](5) NOT NULL,
	[MaDT] [varchar](5) NULL,
	[Diem_CT] [int] NULL,
	[Diem_UV] [int] NULL,
	[Diem_TK] [int] NULL,
	[Diem_PB] [int] NULL,
	[Diem_HD] [int] NULL,
	[TongDiem] [int] NULL,
 CONSTRAINT [PK_LichBaoVe_1] PRIMARY KEY CLUSTERED 
(
	[Nam] ASC,
	[Dot_BV] ASC,
	[MaNganh] ASC,
	[MaSV] ASC
))
GO
/****** Object:  Table [dbo].[Loai_DeTai]    Script Date: 1/6/2023 4:12:56 PM ******/

CREATE TABLE [dbo].[Loai_DeTai](
	[MaLoai] [varchar](5) NOT NULL,
	[TenLoai] [nvarchar](50) NULL,
	[SoTC] [int] NULL,
 CONSTRAINT [PK_Loai_DeTai] PRIMARY KEY CLUSTERED 
(
	[MaLoai] ASC
))
GO
/****** Object:  Table [dbo].[Nganh]    Script Date: 1/6/2023 4:12:56 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Nganh](
	[MaNganh] [varchar](5) NOT NULL,
	[TenNganh] [nvarchar](50) NULL,
	[TruongNganh] [varchar](5) NULL,
	[NamTL] [int] NULL,
 CONSTRAINT [PK_Nganh] PRIMARY KEY CLUSTERED 
(
	[MaNganh] ASC
))
GO
/****** Object:  Table [dbo].[SinhVien]    Script Date: 1/6/2023 4:12:56 PM ******/
CREATE TABLE [dbo].[SinhVien](
	[MaSV] [varchar](5) NOT NULL,
	[HoTen] [nvarchar](50) NULL,
	[KhoaHoc] [int] NULL,
	[MaNganh] [varchar](5) NULL,
 CONSTRAINT [PK_SinhVien] PRIMARY KEY CLUSTERED 
(
	[MaSV] ASC
))
GO
INSERT [dbo].[DeTai_TN] ([MaDT], [TenDT], [LoaiDT], [NienKhoa], [TuNgay], [DenNgay], [MaNganh], [GVHD1], [GVHD2], [XepLoai]) VALUES (N'DT01', N'Hệ tư vấn dựa trên nội dung', N'KL', 2018, CAST(N'2020-09-04' AS Date), CAST(N'2021-04-03' AS Date), N'HTTT', N'GV02', NULL, N'Giỏi')
GO
INSERT [dbo].[DeTai_TN] ([MaDT], [TenDT], [LoaiDT], [NienKhoa], [TuNgay], [DenNgay], [MaNganh], [GVHD1], [GVHD2], [XepLoai]) VALUES (N'DT02', N'Triển khai hệ tư vấn trên hadoop', N'DATN', 2019, CAST(N'2020-12-10' AS Date), CAST(N'2021-07-15' AS Date), N'HTTT', N'GV03', N'GV02', N'Giỏi')
GO
INSERT [dbo].[DeTai_TN] ([MaDT], [TenDT], [LoaiDT], [NienKhoa], [TuNgay], [DenNgay], [MaNganh], [GVHD1], [GVHD2], [XepLoai]) VALUES (N'DT03', N'Phương pháp gom cụm dữ liệu trong phân vùng trang web', N'KL', 2019, CAST(N'2020-09-04' AS Date), CAST(N'2021-04-03' AS Date), N'KTPM', N'GV04', NULL, NULL)
GO
INSERT [dbo].[DeTai_TN] ([MaDT], [TenDT], [LoaiDT], [NienKhoa], [TuNgay], [DenNgay], [MaNganh], [GVHD1], [GVHD2], [XepLoai]) VALUES (N'DT04', N'Xây dựng Chatbot dịch vụ khách hàng', N'KL', 2019, CAST(N'2020-09-04' AS Date), CAST(N'2021-04-03' AS Date), N'HTTT', N'GV01', NULL, NULL)
GO
INSERT [dbo].[DeTai_TN] ([MaDT], [TenDT], [LoaiDT], [NienKhoa], [TuNgay], [DenNgay], [MaNganh], [GVHD1], [GVHD2], [XepLoai]) VALUES (N'DT05', N'Hệ thống quản lý chương trình đào tạo', N'DATN', 2019, CAST(N'2020-09-04' AS Date), CAST(N'2021-04-03' AS Date), N'KTPM', N'GV05', NULL, NULL)
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV01', N'Phạm Nguyễn Cương', N'HTTT', N'TS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV02', N'Lê Nguyễn Hoài Nam', N'HTTT', N'PGS-TS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV03', N'Hồ Thị Hoàng Vy', N'HTTT', N'ThS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV04', N'Nguyễn Văn Vũ', N'KTPM', N'PGS-TS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV05', N'Lâm Quang Vũ', N'KTPM', N'TS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV06', N'Trần Duy Quang', N'KTPM', N'ThS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV07', N'Đinh Điền', N'CNTT', N'PGS-TS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV08', N'Trần Trung Dũng', N'MMT', N'TS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV09', N'Lý Quốc Ngọc', N'TGMT', N'PGS-TS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV10', N'Lê Hoài Bắc', N'KHMT', N'GS-TS')
GO
INSERT [dbo].[GiaoVien] ([MaGV], [HoTen], [MaNganh], [CDKH]) VALUES (N'GV11', N'Nguyễn Trường Sơn', N'HTTT', N'TS')
GO
INSERT [dbo].[HoiDong] ([Nam], [Dot_BV], [MaNganh], [UyVien], [ThuKy], [ChuTichHD], [NgayBV]) VALUES (2021, 1, N'HTTT', N'GV02', N'GV03', N'GV01', CAST(N'2021-04-20T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[HoiDong] ([Nam], [Dot_BV], [MaNganh], [UyVien], [ThuKy], [ChuTichHD], [NgayBV]) VALUES (2021, 1, N'KTPM', N'GV05', N'GV06', N'GV04', CAST(N'2021-04-18T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[HoiDong] ([Nam], [Dot_BV], [MaNganh], [UyVien], [ThuKy], [ChuTichHD], [NgayBV]) VALUES (2021, 2, N'HTTT', N'GV11', N'GV02', N'GV01', CAST(N'2021-07-20T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[LichBaoVe] ([Nam], [Dot_BV], [MaNganh], [MaSV], [MaDT], [Diem_CT], [Diem_UV], [Diem_TK], [Diem_PB], [Diem_HD], [TongDiem]) VALUES (2021, 1, N'HTTT', N'SV01', N'DT01', NULL, 9, 8, 9, 9, NULL)
GO
INSERT [dbo].[LichBaoVe] ([Nam], [Dot_BV], [MaNganh], [MaSV], [MaDT], [Diem_CT], [Diem_UV], [Diem_TK], [Diem_PB], [Diem_HD], [TongDiem]) VALUES (2021, 1, N'HTTT', N'SV02', N'DT01', NULL, 9, 9, 9, 10, NULL)
GO
INSERT [dbo].[LichBaoVe] ([Nam], [Dot_BV], [MaNganh], [MaSV], [MaDT], [Diem_CT], [Diem_UV], [Diem_TK], [Diem_PB], [Diem_HD], [TongDiem]) VALUES (2021, 1, N'KTPM', N'SV03', N'DT03', NULL, NULL, NULL, NULL, NULL, NULL)
GO
INSERT [dbo].[LichBaoVe] ([Nam], [Dot_BV], [MaNganh], [MaSV], [MaDT], [Diem_CT], [Diem_UV], [Diem_TK], [Diem_PB], [Diem_HD], [TongDiem]) VALUES (2021, 1, N'KTPM', N'SV04', N'DT03', NULL, NULL, NULL, NULL, NULL, NULL)
GO
INSERT [dbo].[LichBaoVe] ([Nam], [Dot_BV], [MaNganh], [MaSV], [MaDT], [Diem_CT], [Diem_UV], [Diem_TK], [Diem_PB], [Diem_HD], [TongDiem]) VALUES (2021, 1, N'KTPM', N'SV05', N'DT03', NULL, NULL, NULL, NULL, NULL, NULL)
GO
INSERT [dbo].[LichBaoVe] ([Nam], [Dot_BV], [MaNganh], [MaSV], [MaDT], [Diem_CT], [Diem_UV], [Diem_TK], [Diem_PB], [Diem_HD], [TongDiem]) VALUES (2021, 2, N'HTTT', N'SV06', N'DT02', NULL, NULL, NULL, NULL, NULL, NULL)
GO
INSERT [dbo].[LichBaoVe] ([Nam], [Dot_BV], [MaNganh], [MaSV], [MaDT], [Diem_CT], [Diem_UV], [Diem_TK], [Diem_PB], [Diem_HD], [TongDiem]) VALUES (2021, 2, N'HTTT', N'SV07', N'DT02', NULL, NULL, NULL, NULL, NULL, NULL)
GO
INSERT [dbo].[Loai_DeTai] ([MaLoai], [TenLoai], [SoTC]) VALUES (N'DATN', N'Dự án tốt nghiệp', 6)
GO
INSERT [dbo].[Loai_DeTai] ([MaLoai], [TenLoai], [SoTC]) VALUES (N'KL', N'Khoá luận', 10)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [TruongNganh], [NamTL]) VALUES (N'CNTT', N'Công nghệ tri thức', N'GV07', 2003)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [TruongNganh], [NamTL]) VALUES (N'HTTT', N'Hệ thống thông tin', N'GV01', 1995)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [TruongNganh], [NamTL]) VALUES (N'KHDL', N'Khoa học dữ liệu', NULL, 2020)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [TruongNganh], [NamTL]) VALUES (N'KHMT', N'Khoa học máy tính', N'GV10', 1995)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [TruongNganh], [NamTL]) VALUES (N'KTPM', N'Kỹ thuật phần mềm', N'KTPM', 1995)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [TruongNganh], [NamTL]) VALUES (N'MMT', N'Mạng máy tính', N'GV08', 1997)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [TruongNganh], [NamTL]) VALUES (N'TGMT', N'Thị Giác máy tính', N'GV09', 2003)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [TruongNganh], [NamTL]) VALUES (N'TTNT', N'Trí tuệ nhân tạo', NULL, 2015)
GO
INSERT [dbo].[SinhVien] ([MaSV], [HoTen], [KhoaHoc], [MaNganh]) VALUES (N'SV01', N'Trần Xuân Anh', 2019, N'HTTT')
GO
INSERT [dbo].[SinhVien] ([MaSV], [HoTen], [KhoaHoc], [MaNganh]) VALUES (N'SV02', N'Huỳnh Minh Vương', 2019, N'HTTT')
GO
INSERT [dbo].[SinhVien] ([MaSV], [HoTen], [KhoaHoc], [MaNganh]) VALUES (N'SV03', N'Nguyễn Mỹ Phương', 2019, N'KTPM')
GO
INSERT [dbo].[SinhVien] ([MaSV], [HoTen], [KhoaHoc], [MaNganh]) VALUES (N'SV04', N'Trần Kiều An', 2019, N'KTPM')
GO
INSERT [dbo].[SinhVien] ([MaSV], [HoTen], [KhoaHoc], [MaNganh]) VALUES (N'SV05', N'Trương Thanh Sơn', 2019, N'KTPM')
GO
INSERT [dbo].[SinhVien] ([MaSV], [HoTen], [KhoaHoc], [MaNganh]) VALUES (N'SV06', N'La Tuấn Minh', 2019, N'HTTT')
GO
INSERT [dbo].[SinhVien] ([MaSV], [HoTen], [KhoaHoc], [MaNganh]) VALUES (N'SV07', N'Đinh Khải Nam', 2019, N'HTTT')
GO
ALTER TABLE [dbo].[DeTai_TN]  WITH CHECK ADD  CONSTRAINT [FK_DeTai_TN_Loai_DeTai] FOREIGN KEY([LoaiDT])
REFERENCES [dbo].[Loai_DeTai] ([MaLoai])
GO
ALTER TABLE [dbo].[DeTai_TN] CHECK CONSTRAINT [FK_DeTai_TN_Loai_DeTai]
GO
ALTER TABLE [dbo].[DeTai_TN]  WITH CHECK ADD  CONSTRAINT [FK_DeTai_TN_Nganh] FOREIGN KEY([MaNganh])
REFERENCES [dbo].[Nganh] ([MaNganh])
GO
ALTER TABLE [dbo].[DeTai_TN] CHECK CONSTRAINT [FK_DeTai_TN_Nganh]
GO
ALTER TABLE [dbo].[GiaoVien]  WITH CHECK ADD  CONSTRAINT [FK_GiaoVien_Nganh] FOREIGN KEY([MaNganh])
REFERENCES [dbo].[Nganh] ([MaNganh])
GO
ALTER TABLE [dbo].[GiaoVien] CHECK CONSTRAINT [FK_GiaoVien_Nganh]
GO
ALTER TABLE [dbo].[HoiDong]  WITH CHECK ADD  CONSTRAINT [FK_HoiDong_GiaoVien] FOREIGN KEY([UyVien])
REFERENCES [dbo].[GiaoVien] ([MaGV])
GO
ALTER TABLE [dbo].[HoiDong] CHECK CONSTRAINT [FK_HoiDong_GiaoVien]
GO
ALTER TABLE [dbo].[HoiDong]  WITH CHECK ADD  CONSTRAINT [FK_HoiDong_GiaoVien1] FOREIGN KEY([ThuKy])
REFERENCES [dbo].[GiaoVien] ([MaGV])
GO
ALTER TABLE [dbo].[HoiDong] CHECK CONSTRAINT [FK_HoiDong_GiaoVien1]
GO
ALTER TABLE [dbo].[HoiDong]  WITH CHECK ADD  CONSTRAINT [FK_HoiDong_GiaoVien2] FOREIGN KEY([ChuTichHD])
REFERENCES [dbo].[GiaoVien] ([MaGV])
GO
ALTER TABLE [dbo].[HoiDong] CHECK CONSTRAINT [FK_HoiDong_GiaoVien2]
GO
ALTER TABLE [dbo].[LichBaoVe]  WITH CHECK ADD  CONSTRAINT [FK_LichBaoVe_HoiDong] FOREIGN KEY([Nam], [Dot_BV], [MaNganh])
REFERENCES [dbo].[HoiDong] ([Nam], [Dot_BV], [MaNganh])
GO
ALTER TABLE [dbo].[LichBaoVe] CHECK CONSTRAINT [FK_LichBaoVe_HoiDong]
GO
ALTER TABLE [dbo].[LichBaoVe]  WITH CHECK ADD  CONSTRAINT [FK_LichBaoVe_SinhVien] FOREIGN KEY([MaSV])
REFERENCES [dbo].[SinhVien] ([MaSV])
GO
ALTER TABLE [dbo].[LichBaoVe] CHECK CONSTRAINT [FK_LichBaoVe_SinhVien]
GO

