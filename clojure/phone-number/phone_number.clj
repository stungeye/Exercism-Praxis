(ns phone-number)

(def stub-number "0000000000")

(defn only-digits [n]
  (apply str (filter #(Character/isDigit %) n)))

(defn clean-number [n]
  (let [digits (only-digits n)]
    (if (and (= (count digits) 11)
             (= (first digits) \1))
        (subs digits 1)
        digits)))

(defn number [n]
  (let [cleaned-n (clean-number n)
        valid? (= (count cleaned-n) 10)]
    (if valid? cleaned-n stub-number)))

(defn area-code [n]
  (subs (number n) 0 3))

(defn pretty-print [n]
  (let [n (number n)]
    (format "(%s) %s-%s"
            (area-code n) 
            (subs n 3 6)
            (subs n 6))))
