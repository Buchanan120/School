TITLE Prime Factorization                               (main.asm)

INCLUDE Irvine32.inc
CR = 0Dh
LF = 0Ah

; PROTOTYPES    
Factorialize PROTO,
    compound: DWORD							; Number is assumed to be compound
Modulus PROTO,
    pDividend: DWORD,
    divisor: DWORD

; DECLARATIONS
.data
primeNumber DWORD 2
inputNumber DWORD ?
str1 BYTE "Please input a number to be factored: ",CR,LF,0
star BYTE " * ",0

; PROCEDURES/LOGIC
.code
main PROC
        call Clrscr                                           ; Clear the screen
        call GetInput
        invoke Factorialize, inputNumber
        exit
main ENDP

;-----------------------
GetInput PROC
;
; Prompts the user for an integer.
;-----------------------
        mov edx, OFFSET str1                                ; Point to message
        call WriteString
        
        call ReadInt									; Read in the input
        mov inputNumber, eax
        
        call Crlf

        ret
GetInput ENDP

;-----------------------
Factorialize PROC,
    compound: DWORD
;
; Outputs the prime factorization
;   of a given DWORD.
;-----------------------
Start:
    mov eax, primeNumber                        ; primeNumber is in eax because it needs to be output several times.
    mov ebx, compound
    cmp eax, ebx
    ja Above
NotAbove:
        cmp eax, ebx
        je LastPrime
        
    invoke Modulus, compound, primeNumber  			 ; Modulus remainder stored in edx.
    cmp edx, 0
    jne NotEqual
    
Equal:
    call WriteDec
    
    mov edx, OFFSET star
    call WriteString
    
    mov edx, 0                                  ; divide compound by primeNumber, set it back to compound
    xchg eax, ebx
    div ebx
    mov compound, eax
    xchg ebx, eax
            
    invoke Factorialize, compound        ; Recurse.
    cmp eax, ebx
    je Above
    
NotEqual:
    cmp eax, ebx
    je LastPrime
     
NotPrime:
    add primeNumber, 1
    add eax, 1                    ; Increment the primeNumber
    
    cmp eax, ebx
    jna Start
    jmp Above
    
LastPrime:
    call WriteDec
    call Crlf
        
Above:
    ret
Factorialize ENDP

;-----------------------
Modulus PROC uses eax,
    pDividend: DWORD,
    divisor: DWORD
;
; Returns: The remainder of a division opperation in AL, while preserving the dividend.
;-----------------------
    mov edx, 0                                  ; Clear dividend, high (EAX:EDX/[r/m32])
    mov eax, pDividend                          ; Dividend, low
    
    mov eax, pDividend
    div divisor                                 ; Quotient: EAX, Remainder: EDX
    
    ret
Modulus ENDP
END main
