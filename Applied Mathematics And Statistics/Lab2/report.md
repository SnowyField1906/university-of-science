# LAB 2: Simple Matrix Operations with Python
Teacher: Trần Hà Sơn

Subject: Applied Mathematics and Statistics

<br/>

----

<br/>

## I. Introduction
### 1. Student information
| Full name | Student ID | Class |
| --- | --- | --- |
| Nguyễn Hữu Thuận | 21120566 | 21CTT5 |

### 2. Problem statement
Triển khai hàm ython thực hiện Tích vô hướng và Phân rã QR.

### 3. Problem description
Cho `A` là ma trận có `m` dòng, `n` cột với các phần tử là các số thực. Hãy tìm ma trận `Q` và ma trận `R` sao cho `A = QR`.


## II. Inner Product implementation
### 1. Định nghĩa hàm `innerproduct`
```python
def innerproduct(v1, v2):
```
> Hàm tính tích vô hướng của hai vector `v1` và `v2`. Hàm nhận tham số đầu vào là hai vector `v1` và `v2` và trả về tích vô hướng của hai vector.

### 2. Kiểm tra xem hai vector có thể tích vô hướng với nhau hay không.
```python
if len(v1) != len(v2):
    return None
```
> Nếu hai vector có độ dài khác nhau, hàm sẽ trả về `None` vì không thể tính tích vô hướng hai vector này.

### 3. Tính tích vô hướng
```python
for i in range(len(v1)):
    result += v1[i] * v2[i]
return result
```
> Lặp qua các phần tử của vector, với mỗi `i`, tích phần tử thứ `i` trong `v1` với phần tử thứ `i` trong `v2` và cộng vào biến `result`. Sau đó trả về `result`.


## III. Back Substitution implementation
### 1. Định nghĩa hàm `QR_factorization(A):`
```python
def QR_factorization(A):
```
> Hàm phân tích ma trận `A` thành hai ma trận `Q` và `R` sao cho `A = QR`. Hàm nhận tham số đầu vào là ma trận `A` và trả về hai ma trận `Q` và `R`.

### 2. Khởi tạo các kích thước của ma trận `A`
```python
m, n = len(A), len(A[0])
```
> `m` là số dòng của `A`, `n` là số cột của `A`.

### 3. Khởi tạo ma trận `Q` và `R`
```python
Q = [[0] * m for _ in range(n)]
R = [[0] * n for _ in range(n)]
```
> Tạo hai ma trận `Q` và `R` lần lượt có kích thước là `m x n` và `n x n` với các phần tử được đặt là `0`.

### 4. Vòng lặp bên ngoài
```python
for j in range(n):
    v = [A[i][j] for i in range(m)]
```
> Lặp qua các cột của `A`, với mỗi dòng, tạo một vector `v` chứa các phần tử của cột thứ `j` của ma trận A.

### 5. Vòng lặp bên trong 1
```python
for i in range(j):
    R[i][j] = innerproduct(Q[i], v)
    v = [v[k] - R[i][j] * Q[i][k] for k in range(m)]
```
> **Gram-Schmidt**: Lặp đến cột `j`, trong mỗi lần lặp, lưu giá trị tích vô hướng của `Q[i]` và `v` vào `R[i][j]`. Sau đó, với mỗi dòng `k` trong `m`, trừ `R[i][j] * Q[i][k]` với `v[k]`. Điều này là để tính toán hình chiếu của `v` lên mỗi vector trực chuẩn trong `Q` và lưu nó trong phần tử tương ứng của `R`. Sau đó, nó trừ các phép chiếu này khỏi `v` để thu được một vector mới trực giao với các vector trực giao trước đó.

### 6. Cập nhật đường chéo
```python
R[j][j] = innerproduct(v, v) ** 0.5
```
> Tính **norm** của `v` và lưu vào đường chéo thứ j của `R`.

### 7, Vòng lặp bên trong 2
```python
for i in range(m):
    Q[i][j] = v[i] / R[j][j]
```
> Chuẩn hóa `v` và lưu vào cột thứ `j` của `Q`.

## IV. Technical details
- Sử dụng thư viện `numpy` để đọc file `input.txt`
- Hàm `print_matrix()` được sử dụng để in ma trận ra console theo định dạng đẹp

## V. Usage
1. Nhập ma trận `A` vào file `input.txt` theo định dạng sau:
```
1 -2 3 -4
5 -6 7 -8
9 -10 11 -12
```
2. Chạy chương trình `21120566.py` để phân tích ma trận `A` thành hai ma trận `Q` và `R` sao cho `A = QR`.
3. Kết quả sẽ được xuất ra console như sau:
- Nếu `R` không phải là ma trận đây đủ: `Matrix is not full rank`
- Nếu `R` là ma trận đây đủ: Thông tin về ma trận `Q` và `R` sẽ được xuất ra console theo định dạng

## VI. Example
`input.txt`

[![1]][1]

`console`

[![2]][2]

  [1]: https://i.imgur.com/ITk2Sb4.png
  [2]: https://i.imgur.com/Sn6k0TV.png

## VII. References
- [Systems of Linear Equations](https://courses.fit.hcmus.edu.vn/pluginfile.php/190403/mod_resource/content/1/B1_System%20Linear%20Equations.pdf)