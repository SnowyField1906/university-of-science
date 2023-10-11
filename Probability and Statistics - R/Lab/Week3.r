* Week 3:

** Câu 1
*** a
#+NAME: cau_1a_func
#+BEGIN_SRC R
k = 0:8;
p = function(k) choose (8, k) * 0.3^k + 0.7^(8 - k);
p(k);
#+END_SRC

#+RESULTS: k
| 1.05764801 |
|  2.4823543 |
|   2.637649 |
|    1.68007 |
|     0.8071 |
|    0.47908 |
|   0.510412 |
|  0.7017496 |
| 1.00006561 |

#+NAME: cau_1a_sum
#+BEGIN_SRC R :noweb yes
<<cau_1a_func>>
sum(p(k))
#+END_SRC

#+RESULTS: cau_1a_sum
: 11.35612852

*** b
#+name: cau_1b_func
#+begin_src R
f = function(x, mu = 0, sigma = 1) {
  1/sqrt(2 * pi * sigma^2) * exp(-(x - mu)^2/(2 * sigma^2))
}
#+end_src

#+begin_src R :noweb yes
<<cau_1b_func>>
f(0)
#+end_src

#+RESULTS:
: 0.398942280401433



** Câu 2
*** a
#+NAME: cau_2a
#+begin_src R :noweb yes :results output graphics :file cau2a.png
<<cau_1a_func>>
plot(k, p(k), type = "h", ylab = "P(X = x)")
#+end_src

#+RESULTS: cau_2a

*** b
#+NAME: cau_2b
#+begin_src R :noweb yes :results output graphics :file cau2b.png
<<cau1a_func>>
<<cau1b_func>>
curve(f(x, 0, 1), from = -3, to = 3, ylab = "fX(x)")
#+end_src

#+RESULTS: cau_2b


** Week 4

#+BEGIN_SRC R

#+END_SRC
