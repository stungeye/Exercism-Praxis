(ns point-mutations)

(defn hamming-distance [strand1 strand2]
  (when (= (count strand1) (count strand2)) 
    (let [point-mutations (map not= strand1 strand2)]
      (count (filter true? point-mutations)))))
