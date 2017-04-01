proc printf(formatstr:cstring)
  {.header:"<stdio.h>",varargs.}
proc scanf(formatstr:cstring)
  {.header:"<stdio.h>",varargs.}

proc hcf*(n: cint; m: cint): cint =
  if n == m: return n
  if n > m: return hcf(n - m, m)
  return hcf(n, m - n)

proc main*(): cint =
  var
    m: cint
    n: cint
  var nod: cint
  printf("input n*m != 0\x0A")
  scanf("%d%d", addr(n), addr(m))
  if n == 0 or m == 0:
    nod = abs(n) + abs(m)
    if nod == 0:
      printf("\xD0\x9D\xD0\x9E\xD0\x94 \xD0\xB4\xD0\xBB\xD1\x8F \xD0\xBD\xD1\x83\xD0\xBB\xD0\xB5\xD1\x84\xD1\x8B\xD1\x85 \xD1\x87\xD0\xB8\xD1\x81\xD0\xB5\xD0\xBB \xD0\xBD\xD0\xB5 \xD0\xBE\xD0\xBF\xD1\x80\xD0\xB5\xD0\xB4\xD0\xB5\xD0\xBB\xD1\x91\xD0\xBD\x0A")
      return 0
  else:
    nod = hcf(abs(n), abs(m))
  printf("(%d,%d)=%d\x0A", n, m, nod)
  return 0
discard main()