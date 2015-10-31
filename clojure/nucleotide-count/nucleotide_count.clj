(ns nucleotide-count)

(def empty-counts {\A 0, \T 0, \C 0, \G 0})

(def memo-frequencies (memoize frequencies))

(defn nucleotide-counts [strand] 
  (into empty-counts (memo-frequencies strand)))

(defn count [nucleotide strand] 
  (or (get (nucleotide-counts strand) nucleotide)
      (throw (Exception. "invalid nucleotide"))))

