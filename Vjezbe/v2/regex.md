### Zadatak 1
``` regex
^0x[\da-f]+$
```

### Zadatak 2
``` regex
^[_\D]([\d\w_])+$
```

### Zadatak 3
``` regex
^[+-]?\d+(\.\d+)?([eE][+-]?\d+)?$
```

### Zadatak 4
``` regex
^([+]\d{2,3})?[0 -]?6\d([- ]?\d{3}){2}$
```

### Zadatak 5
``` regex
href=".*?"
href="[^"]*"
```

`.*` je *greedy*, match-ira koliko moze. Tako da `".*"` matchira sve od prvog `"` do zadnjeg `"`.

`.*?`
