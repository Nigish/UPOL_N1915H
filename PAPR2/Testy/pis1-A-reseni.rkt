;; Vyraz k vyhodnoceni

(let ((c 0))
  ((lambda (x y z)
     (if (null? y) (mcons x (mcons z '()))
         (mcons x (let iter ((w y))
                    (set! c (+ c 1))
                    (if (null? (mcdr w))
                        (begin
                          (set-mcdr! w (mcons z '()))
                          y)
                        (iter (mcdr w)))))))
   2
   (mcons 1 (mcons 3 ()))
   c))

;; Fronta

(define make-queue
  (lambda ()
    (let ((first '())
          (last '()))
      
      (define empty?
        (lambda ()
          (and (null? first) (null? last))))
      
      (define read
        (lambda ()
          (cond ((empty?) (error "Queue is empty. ")) 
                ((equal? first last) (let ((out (mcar first)))
                                       (set! first '())
                                       (set! last '())
                                       out))
                (else (let ((out (mcar first)))
                        (set! first (mcdr first))
                        out)))))
      
      (define write
        (lambda (el)
          (let ((new (mcons el '())))
            (if (empty?)
              (begin
                (set! first new)
                (set! last new))
              (begin
                (set-mcdr! last new)
                (set! last new))))))
      
      (lambda (message . args)
        (cond ((equal? message 'empty?) (empty?))
              ((equal? message 'read) (read))
              ((equal? message 'write) (write (car args)))
              ((equal? message 'get) (cons first last))
              (else (error "Unknown message!")))))))

;(define test (make-queue))
;test
;(test 'get)
;(test 'empty?)
;(test 'write 1)
;(test 'write 2)
;(test 'empty?)
;(test 'get)
;(test 'read)
;(test 'get)
;(test 'read)
;(test 'empty?)
;(test 'get)


;; Makro dosquares

(define-macro dosquares
  (lambda (n from to . body)
    (let ((loop-name (gensym))
          (num (gensym)))
      `(let ,loop-name ((,num ,from))
         (let ((,n (* ,num ,num)))
           ,@body
           (if (< ,num ,to) (,loop-name (+ 1 ,num))))))))

;(dosquares n 5 10 (display n) (display " "))
;(newline)
;(let ((sum 0))
;  (dosquares n 1 10 (set! sum (+ sum n)))
;  sum)