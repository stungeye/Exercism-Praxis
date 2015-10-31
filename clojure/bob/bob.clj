(ns bob)

(defn contains-uppercase? [sentence]
  ; Contains at least one uppercase letter.
  (re-find #"[A-Z]" sentence))

(defn contains-no-lowercase? [sentence]
  ; Negative lookahead to ensure that no  lowercase letters are present.
  (re-find #"^(?!.*[a-z]).+$" sentence))

(defn silence? [sentence]
  ; Silence is a empty string or any length of whitespace.
  (re-find #"^\s*$" sentence))

(defn yelling? [sentence]
  (and 
    (contains-uppercase? sentence)
    (contains-no-lowercase? sentence)))

(defn question? [sentence]
  ; Questions end in question marks,
  ; but yelled questions are not included.
  (and 
      (re-find #"\?$" sentence)
      (not (yelling? sentence))))

(defn response-for [sentence] 
  (cond
    (silence? sentence) "Fine. Be that way!"
    (question? sentence) "Sure."
    (yelling? sentence) "Whoa, chill out!"
    :else "Whatever."))
