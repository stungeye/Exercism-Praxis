(ns etl (:require [clojure.string :as str]))

(defn transform [points-to-letters]
  (into {} 
        (for [[point letters] points-to-letters, letter letters]
             [(str/lower-case letter) point])))
