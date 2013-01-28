TITLE I/O Sum                                   (IOsum.asm)

INCLUDE Irvine32.inc
; Makes input show on next line:
CR = 0Dh ; Carrige-return
LF = 0Ah ; Line-feed

.data
str1 BYTE "Please input a number: ",CR,LF,0
str2 BYTE "Please input a second number: ",CR,LF,0
str3 BYTE "Total: ",0

number1 DWORD ? ; User input 1
number2 DWORD ? ; User input 2

.code
main PROC
        call Clrscr
        call PromptForIntegers
        call SumOfNumbers
        call DisplaySum
        exit
main ENDP

;-----------------------
PromptForIntegers PROC
;
; Prompts the user for two integers.
; Recieves: Nothing
; Returns: Nothing
;-----------------------        
        mov edx, OFFSET str1
        call WriteString
        call ReadInt
        call Crlf
        mov number1, eax

        mov edx, OFFSET str2
        call WriteString
        call ReadInt
        call Crlf
        mov number2, eax
        ret
PromptForIntegers ENDP

;-----------------------
SumOfNumbers PROC
;
; Calculates the sum of two numbers.
; Recieves: Nothing
; Returns: EAX = sum of numbers.
;-----------------------
        mov eax, number1
        mov ebx, number2
        add eax, ebx
        ret
SumOfNumbers ENDP

;-----------------------
DisplaySum PROC
;
; Displays the sum of two integers on the screen.
; Recieves: EAX = total sum
; Returns: Nothing
;-----------------------
        mov edx, OFFSET str3
        call WriteString
        call WriteInt
        call Crlf
        ret
DisplaySum ENDP
END main