#lang racket/base

(define eratosthenes 
  (lambda (n)
    (define (sift list)
      (filter (lambda (n)
                (not (zero? (modulo n (car list)))))
              list))
    (let loop ((list (cdr (build-list n add1))))
      (let ((p (car list)))
        (if (> (* p p) n)
            list
            (cons p (loop (sift list))))))))
(define contains?
  (lambda (x list)
    (cond
     ((null? list) #f)
     (else (or (eq? (car list) x)
               (contains? x (cdr list)))))))
(define largest
  (lambda (list)
    (cond
      ((null? (cdr list)) (car list))
      ((> (car list) (largest (cdr list))) (car list))
      (else
       (largest (cdr list))))))


;; Contract: print-my-info : nothing -> string string string
;; Purpose: A function that displays your name, the course code for 
;;          this course, and the assignment name for this assignment 
;;          on three separate lines
;; Example: (print-my-info) should print: "Caleb Thompson"
;;                                        "CSC381"
;;                                        "Assignment 3.2 - Scheme Basics"
(define print-my-info
  (lambda ()
    (display "Caleb Thompson")
    (newline)
    (display "CSC318")
    (newline)
    (display "Assignment 3.2 - Scheme Basics")
    (newline)))

;; Test:
(print-my-info)

;; Contract: rectangle-area : number number -> number
;; Purpose: A function that calculates the area of a rectangle with a
;;          given height and width
;; Example: (rectangle-area 5 4) should produce 20

(define rectangle-area
  (lambda(height width)
    (* height width)))

;; Test:
(rectangle-area 5 4) ;; expected value = 20


;; Contract: larger : number number -> number
;; Purpose: A function that takes two number arguments and returns the
;;          largest
;; Example (larger 8 1) should produce 8
(define larger
  (lambda (x y)
    (cond
      ((> x y) x)
      (else y))))

;; Test:
(larger 8 1) ;; expected value = 8

;; Contract: sum-between : number number -> number
;; Purpose: A function that takes two number arguments and returns the
;;          sum of all numbers between them (including the arguments –
;;          so if the arguments are 3 and 5, then the function would 
;;          return 12)
;; Example: (sum-between 1 5) should produce 15
(define sum-between
  (lambda (x y)
    (cond
      ((> x y) -1)
      ((= x y) y)
      (else (+ x (sum-between (+ x 1) y))))))
;; Test:
(sum-between 1 5) ;; Should be 15

;; Contract: fibonacci : number -> number
;; Purpose: A function that takes a number argument and returns the 
;;          Fibonacci number at that index in the list of Fibonacci
;;          numbers.  The first two Fibonacci numbers at indexes zero
;;          and one are 0 and 1. The Fibonacci number at index ten is 
;;          55, so given the argument 10 your function would return 55
;; Example: (fibonacci 5) should give 5
(define fibonacci
  (lambda (x)
    (fibonacci-helper-function x 0 1)))
(define fibonacci-helper-function
  (lambda (x base-0 base-1)
    (cond
      ((zero? x) base-0)
      ((zero? (- x 1)) base-1)
      (else (fibonacci-helper-function (- x 1) base-1 (+ base-0 base-1))))))

;; Test:
(fibonacci 10) ;; Should be 55

;; Contract: prime? : number -> bool
;; Purpose: A function that take a number argument and returns a value
;;          indicating whether or not the argument is prime
;; Example: (prime? 4) should give #f
(define prime?
  (lambda (n)
    (contains? n (eratosthenes n))))

;; Contract: filter-primes : list -> list
;; Purpose: A function that takes a list of numbers and returns a list
;;          of numbers that contains all the prime numbers in the 
;;          argument list
;; Example: (filter-primes 11 12 13 14 15) should give (11 13)
(define filter-primes
 (lambda (list)
   (cond
     ((null? list) '())
     ((prime? (car list))
      (cons (car list) (filter-primes (cdr list))))
     (else
      (filter-primes (cdr list))))))
;; Test:
(filter-primes '(11 12 13 14 15))

;; Contract: largest-prime : list -> number
;; Purpose: A function that take a list of numbers and returns the 
;;          largest prime number in the list
;; Example: (largest-prime 2 11 3 7) should give 11
(define largest-prime
 (lambda (list)
   (largest (filter-primes list))))
;; Test:
(largest-prime '(2 11 3 7))

;; Contract: primes<= : number -> list
;; Purpose: A function that takes a number argument and returns a list
;;          of prime numbers that are less than or equal to the 
;;          argument
;; Example: (primes<= 11) should give (2 3 5 7 11) 
(define primes<=
  (lambda (list)
    (eratosthenes list)))
;; Test:
(primes<= 11)


;; Contract: intersection : list list -> list
;; Purpose: A function that takes two lists of numbers and returns a 
;;          list of numbers that are in both argument lists. Give the
;;          lists (1 2 3 4 5) and (1 3 5 7 9) the function would 
;;          return the list (1 3 5).
;; Example: (intersection '(1 2 3 4 5) (primes<= 11)) should give
;;          '(2 3 5)
(define intersection
  (lambda (listA listB)
    (cond
      ((or (null? listA) (null? lisbB))'())
      ((contains? (car listA) listB)
       (cons (car listA) (intersection (cdr listA) listB)))
      (else
       (intersection (cdr listA) listB)))))
;; Test: 
(intersection '(1 2 3 4 5) (primes<= 11))

  
  
  
         