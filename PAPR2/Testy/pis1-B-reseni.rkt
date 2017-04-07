;; Vyraz k vyhodnoceni

(let* ((x (+ 2 5))
       (y `(1 ,x 2 ,(+ x 2))))
  (let z ((i y))
    (if (null? i) x
        (begin
          (set! x (+ x (car i)))
          (z (cdr i))))))

;; Seznam

(define make-list
  (lambda ()
    (let ((data '()))
      
      (define empty?
        (lambda ()
          (null? data)))
      
      (define insert
        (lambda (item index)
          (if (= index 0) 
              (set! data (mcons item data))
              (let iter ((pos data)
                         (i index))
                (if (null? pos) (error "Index out of range. "))
                (if (> i 1) (iter (mcdr pos) (- i 1))
                    (set-mcdr! pos (mcons item (mcdr pos))))))))
      
      (define delete
        (lambda (index)
          (if (empty?) (error "Can not delete from empty list. ")
          (if (= index 0) (set! data (mcdr data))
              (let iter ((pos data)
                         (i index))
                (if (or (null? pos) (null? (mcdr pos))) (error "Index out of range. "))
                (if (> i 1) (iter (mcdr pos) (- i 1))
                    (set-mcdr! pos (mcdr (mcdr pos)))))))))
      
      (lambda (message . args)
        (cond ((equal? message 'empty?) (empty?))
              ((equal? message 'insert) (insert (car args) (cadr args)))
              ((equal? message 'delete) (delete (car args)))
              ((equal? message 'data) data)
              (else (error "Unknown message!")))))))

;(define test (make-list))
;(test 'data)
;(test 'insert 'a 0)
;(test 'data)
;(test 'insert 'b 0)
;(test 'insert 'c 0)
;(test 'data)
;(test 'insert 'd 3)
;(test 'data)
;(test 'delete 1)
;(test 'data)

;; Makro swap

(define-macro swap
  (lambda (a b)
    (let ((pom (gensym)))
      (if (and (symbol? a)
               (symbol? b))
          `(let ((,pom ,a))
             (set! ,a ,b)
             (set! ,b ,pom))
          (error "Makro pracuje jen se symboly.")))))

;(define x 5)
;(define y #t)
;(swap x y)
;x
;y
;(swap x 2)