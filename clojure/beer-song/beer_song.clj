(ns beer-song
  (:require [clojure.string :as str]))

(def max-bottles 99)

(defn bottles [n]
  (cond
    (zero? n) "no more bottles"
    (= n 1)   "1 bottle"
    :else     (str n " bottles")))

(defn taken-bottle [n]
  (if (= n 1) "it" "one"))

(defn verse [n]
  (let [part-1 [(str/capitalize (bottles n))
                " of beer on the wall, "
                (bottles n)
                " of beer.\n"]
        part-2 (if-not (zero? n)
                  ["Take "
                   (taken-bottle n)
                   " down and pass it around, "
                   (bottles (dec n))]
                  ["Go to the store and buy some more, "
                   (bottles max-bottles)])
        part-3 " of beer on the wall.\n"]
    (str/join (concat part-1 part-2 part-3))))

(defn verses [start_n end_n]
  (map verse (range start_n (dec end_n) -1)))

(defn sing
  ([start_n]
    (sing start_n 0))
  ([start_n end_n]
    (str/join "\n" (verses start_n end_n))))

