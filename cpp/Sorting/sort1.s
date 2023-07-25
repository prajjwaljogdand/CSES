;<Program title>

    MVI A, 70H      ; "Store 70H in the accumulator"
    LXI B,0000H     ; "load starting address into HL"
    STAX B

    MVI A, 3EH      ; "Store 3EH in the accumulator"
    INX B           ; "Increment memory address"
    STAX B          ; "Copy accumulator contents at address 2502H"

    MVI A, 13H      ; "Store 13H in the accumulator"
    INX B           ; "Increment memory address"
    STAX B          ; "Copy accumulator contents at address 2503H"

    MVI A, ABH      ; "Store ABH in the accumulator"
    INX B           ; "Increment memory address"
    STAX B          ; "Copy accumulator contents at address 2504H"

    MVI A, 76H      ; "Store 76H in the accumulator"
    INX B           ; "Increment memory address"
    STAX B           ; "Copy accumulator contents at address 2505H"


    MVI C,5            ; "Init c with 5"

  	INIT: DCR C;
          JZ STOP; "Jump if C is Zero to STOP"
          LXI H,0000H;
          MVI D,4;
          JMP SORT;

    SORT: MOV A, M     ; "load number from HL memory address into A"
          INX H        ; "Increment HL memory address"
          CMP M        ; "compare current number with next number"
          JC SKIP      ; "if current number is less than or equal to next number, skip swapping"
          MOV E, A     ; "load next number into E"
          MOV A, M     ; "load current number into A"
          MOV M, E     ; "store next number at current memory address"
          DCX H        ;  "Decrement memory address"
          MOV M, A     ;  "store current number at next memory address"
          INX H        ;  "Increment memory address"
          DCR D        ;  "Decrement D"
          JZ INIT      ; "Jump if D is Zero to start next Interation"
          JMP SORT     ; "repeat sorting loop"
    SKIP: DCR D        ; "compare current memory address with end address"
          JZ INIT      ; "Jump if D is Zero to start next Interation"
          JMP SORT     ; "repeat sorting loop"
    STOP: HLT          ; "stop execution"  