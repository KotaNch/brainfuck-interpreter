# bf 

Small brainfuck interpreter written in C.

## Build 

```bash
make 
```

Needs `clang`.

## Usage 

```bash 
./bf program.bf
./bf tests/hello.bf
printf 'abc' | ./bf tests/reverse.bf 
```

## Commands

`<` `>` - move the pointer right/left 
`+` `-` - increment / decrement the current cell 
`.` - print the current cell as a ASCII character
`,` - read one character into the current cell 
`[` `]` - loop while the current cell is not zero 

## Tests 

```bash 
make test 
```

