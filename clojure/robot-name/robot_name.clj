(ns robot-name)

(def ^:private capital-chars
    (map char (range (int \A) (inc (int \Z)))))

(defn- random-name []
  (format "%s%s%03d" 
          (rand-nth capital-chars)
          (rand-nth capital-chars)
          (rand-int 9999)))

(defrecord Robot [name])

(defn robot []
  (Robot. (atom (random-name))))

(defn robot-name [robot]
  @(:name robot))

(defn reset-name [robot]
  (reset! (:name robot) (random-name)))
