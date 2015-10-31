(ns grade-school)

(defn add [db name num]
  (merge-with concat db {num [name]}))

(defn grade [db num]
  (vec (get db num)))

(defn sorted [db]
  (into (sorted-map)
        (for [[num names] db] [num (sort names)])))
