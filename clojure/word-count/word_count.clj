(ns word-count
  (:require [clojure.string :as str]))

(defn words-in [phrase]
  (re-seq #"\b[^\s]+\b" phrase))

(defn lower-case-words-in [phrase]
  (map str/lower-case (words-in phrase)))

(defn word-count [phrase]
  (frequencies (lower-case-words-in phrase)))
