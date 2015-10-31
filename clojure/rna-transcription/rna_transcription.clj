(ns rna-transcription)

(defn rna-transcribe [dna-nucleotide]
  { :post [%] }
  (let [dna-to-rna  { \G \C, \C \G, \T \A, \A \U }]
     (dna-to-rna dna-nucleotide)))

(defn to-rna [strand]
  (apply str (map rna-transcribe strand)))
