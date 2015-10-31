(ns leap)

(def multiple-of? 
  (comp zero? mod))

(defn leap-year? [year]
  (and (multiple-of? year 4)
       (or (multiple-of? year 400)
           (not (multiple-of? year 100)))))
