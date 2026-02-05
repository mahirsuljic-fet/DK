## [Zadatak 1](https://regexone.com/)

#### Lesson 1
``` regex
\w+
```

#### Lesson 2
``` regex
\d+
```

#### Lesson 3
``` regex
.*\.
```

#### Lesson 4
``` regex
[cmf]an
```

#### Lesson 5
``` regex
[^b]og
```

#### Lesson 6
``` regex
[A-Z].*
```

#### Lesson 7
``` regex
wazz+up
```

#### Lesson 8
``` regex
aa.*
```

#### Lesson 9
``` regex
\d+ files? found\?
```

#### Lesson 10
``` regex
\d+\.\s+abc
```

#### Lesson 11
``` regex
^Mission.*
```

#### Lesson 12
``` regex
^(file.*)\.pdf
```

#### Lesson 13
``` regex
(\w+ (\d+))
```

#### Lesson 14
``` regex
(\d+)x(\d+)
```

#### Lesson 15
``` regex
I love (cats|dogs)
```

#### Lesson 16
``` regex
.*
```

#### Problem 1
``` regex
[+-]?\d+(\,\d+)?(\.\d+(e\d+)?)?$
```

#### Problem 2
``` regex
(\d\s)?\(?(\d{3})\)?([-\s]?\d{3,4}){2}
```

#### Problem 3
``` regex
rješenje: ([\w\.]+)
sve:      ([\w\.]+)(\+\w+)?@[\w\.]+
```

#### Problem 4
``` regex
rješenje: <(\w+)
sve:      <(\w+).*?>.*</\w+>
```

#### Problem 5
``` regex
([\w]+)\.(jpg|png|gif)$
```

#### Problem 6
``` regex
^\s+(.*)\s*$
```

#### Problem 7
``` regex
at \w+\.\w+\.(\w+)\((.*?):(\d+)\)
```

#### Problem 8
``` regex
(\w+)://([\w-]+(\.\w+)?)(:(\d+))?/.*
```


## Zadatak 2

``` regex
trenutne, stare:  ([AEOJKMT]|\d)\d{2}-[AEOJKMT]-\d{3}
taxi, privremene: T[TA]-\d{6}
diplomatske:      \d{2}-[ACME]-\d{3}

sve: (([AEOJKMT]|\d)\d{2}-[AEOJKMT]-\d{3})|(T[TA]-\d{6})|(\d{2}-[ACME]-\d{3})
ili: ((([AEOJKMT]|\d)\d{2}-[AEOJKMT]-)|(T[TA]-\d{3})|(\d{2}-[ACME]-))\d{3}
```

## Zadatak 3

``` regex
simple: \d{1,3}(\.\d{1,3}){3}(:\d{1,5})?

id:   0|1\d{0,2}|2[0-4]\d|25[0-5]
port: [1-5]?\d{1,4}$|6[0-4]\d{3}|65[0-5][0-3][0-5]

strict: (0|1\d{0,2}|2[0-4]\d|25[0-5])(\.(0|1\d{0,2}|2[0-4]\d|25[0-5])){3}(:([1-5]?\d{1,4}$|6[0-4]\d{3}|65[0-5][0-3][0-5]))?
```
