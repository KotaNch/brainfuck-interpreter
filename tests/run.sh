#!/bin/sh
fail() {
  echo "FAIL $1"
  exit 1
}

out=$(./bf tests/hello.bf)
[ "$out" = "Hello World!" ] || fail hello

out=$(printf 'abc' | ./bf tests/cat.bf)
[ "$out" = "abc" ] || fail cat

out=$(printf 'abc' | ./bf tests/reverse.bf)
[ "$out" = "cba" ] || fail reverse

out=$(./bf tests/nested.bf)
[ "$out" = "A" ] || fail skip

out=$(./bf tests/add.bf)
[ "$out" = "5" ] || fail add

out=$(./bf tests/comments.bf)
[ "$out" = "A" ] || fail comments

out=$(./bf tests/empty.bf)
[ -z "$out" ] || fail empty
./bf tests/empty.bf || fail empty_status

for f in bad_open bad_close underflow; do
  ./bf tests/$f.bf 2>/dev/null && fail $f
done

./bf tests/nope.bf 2>/dev/null && fail missing_file

echo ok
