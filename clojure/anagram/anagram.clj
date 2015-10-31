(ns anagram
  (:require [clojure.string :as str]))

(defn anagram? [word1 word2]
  (let [word1 (str/lower-case word1)
        word2 (str/lower-case word2)]
    (and 
     ; A word is not its own anagram.
     (not= word1 word2)
     ; Anagrams have identical character frenquenies.
     (= (frequencies (char-array word1))
        (frequencies (char-array word2))))))

(defn anagrams-for [word potential-anagrams]
  (filter (partial anagram? word) potential-anagrams))
