TITLE Letter Count                                      (StringCounter.asm)

INCLUDE Irvine32.inc
CR = 0Dh
LF = 0Ah

; PROTOTYPES
Str_ucase PROTO,
        pString:PTR BYTE
        
GetElementAtIndex PROTO,
        pArray: PTR BYTE,
        myByte: WORD
        
.data
; DECLARATIONS
strInput BYTE "Please input a string: ",CR,LF,0
strMax BYTE "The letter with the most occurance is: ",0
strMin BYTE "The letter with the least occurance is: ",0
strAvg BYTE "The average occurance of letters used is: ",0
space BYTE " ",0

inString BYTE 10000 DUP(0)
stringLength DWORD ?

alphabet BYTE 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
letterCount BYTE 26 DUP(0)

arrayOffset WORD 0
counter WORD 0

Max BYTE 0
Min BYTE 0
Avg BYTE 0

.code
main PROC
        call Clrscr                                             ; Clear the screen
        call GetInput                                   ; Get the user input string
        call CountLetters                               ; Count the number of letters in the string
        call OutputLetterCount                  ; DEBUG: Show the count array
        call CalcMaxLetter                              ; Calculate the letter used the most
        call CalcMinLetter                              ; Calculate the letter used the least
        call CalcAvgLetter                              ; Calculate the average number of letters in the string
        call OutputMaxMinAvg                    ; Output information to the user
        exit
main ENDP

;-----------------------
GetInput PROC
;
; Prompts the user for a string of characters.
;       Sets the string to uppercase to be case insensitive.
;-----------------------
        mov edx, OFFSET strInput                    ; Point to message
        call WriteString
        
        mov edx, OFFSET inString                ; Point to buffer
        mov ecx,(SIZEOF inString)               ; Specify max characters for input
        call ReadString
        mov stringLength, eax                   ; Get the length of input
        INVOKE Str_ucase,ADDR inString  ; Make the string case-insensitive
        call Crlf

        ret
GetInput ENDP

;-----------------------
CountLetters PROC
;
; Counts the letters in the user input string and increments the letterCount
;       using the index of the alphabet array for the index of letterCount.
;-----------------------
        pushad  ; Preserve registers
        
        mov eax, 0
        mov ebx, 0
        
        mov esi, OFFSET inString                ; Point to input String
        mov ecx, stringLength                   ; Set loop counter to string length
L1:
        mov arrayOffset, 0                              ; Reset arrayOffset
        mov al, [esi]                                   ; Begin loop at first character of string
        push esi                                                ; Preserve esi, and ecx because we are moving into a nested loop
        push ecx
        
        mov esi, OFFSET alphabet                ; Point to alphabet string
        mov ecx, SIZEOF alphabet                ; Set inner loop counter to length of alphabet (26)
        
L2:
        mov bl, [esi]                                   ; Set the letter of the alphabet in esi. (1. inString[0], A)
        cmp al, bl                                              ; Check if the characters are equal
        jne NotEqual                                    ; If not, jump to NotEqual
Equal:
        push esi                                                ; Preserve pointer to array, need to point to letterCount
        
        mov esi, OFFSET letterCount
        add si, arrayOffset                             ; Move the pointer to the offset of the alphabet letter
        inc BYTE PTR [esi]                              ; Increment that position. letterCount[x]++
        
        pop esi
        
NotEqual:
        inc arrayOffset                                 ; Increment arrayOffset to point to next letter in alphabet
        inc esi                                                 ; Point to next element
        loop L2
                                                                        ; END OF LOOP 2
        pop ecx
        pop esi
        
        inc esi                                                 ; Point to the next element in the input string.
        loop L1
                                                                        ; END OF LOOP 1
        popad
        ret
CountLetters ENDP

;-----------------------
OutputLetterCount PROC USES eax ecx edi
;
; Prints the letterCount array to see what elements have been
;       incremented.
;-----------------------
        mov esi, OFFSET letterCount
        mov edi, OFFSET alphabet
        mov ecx, LENGTHOF letterCount
L1:
        mov eax, 0
        mov al, [edi]
        call WriteChar
        mov edx, OFFSET space
        call WriteString
        mov al, [esi]
        call WriteDec
        call Crlf
        inc esi
        inc edi
        loop L1
                                                                        ; END LOOP 1
        call Crlf
        ret
OutputLetterCount ENDP

;-----------------------
CalcMaxLetter PROC
;
; Looks through the letterCount array for the item with the
;       highest count. Assigns that number to Max.
;       Max is equal to the number of times a letter has been 
;       input, not the letter itself. arrayOffset is used for the
;       actual letter.
;-----------------------
        mov esi, OFFSET letterCount     ; Point to letterCount array
        mov ecx, LENGTHOF letterCount   ; Setup counter to size of the array for loop
L1:
        mov al, Max
        mov bl, [esi]
        cmp bl, al                                              ; if bl{max} !> al{current lettercount}
        jng NotGreater                                  ; True = bl > al
Greater:
        mov Max, bl                                     ; Set max to bl, it is the current max until we find another.
        mov dx, counter                                 ; Counter for current array element.
        mov arrayOffset, dx                             ; arrayOffset will be used to give us the actual letter
NotGreater:
        inc esi
        inc counter
        loop L1
                                                                        ; END LOOP 1
        INVOKE GetElementAtIndex, ADDR alphabet, arrayOffset ; Convert the max counted letter into an actual letter
        mov Max, bl                                                                                      ; Stored in bl, so move to max
        ret
CalcMaxLetter ENDP

;-----------------------
CalcMinLetter PROC
;
; Looks through the letterCount array for the item with the
;       lowest count. Assigns that number to Min.
;       Min is equal to the number of times a letter has been 
;       input, not the letter itself. arrayOffset is used for the
;       actual letter.
;-----------------------
        mov al, Max
        mov Min, al                                             ; Set min to the max. Max is used as an upward bound.
        
        mov esi, OFFSET letterCount
        mov ecx, LENGTHOF letterCount
        mov counter, 0                                  ; Reset the counter since it was used before in CalcMaxLetter
L1:
        mov al, Min                                             ; Set al to the min to compare it to current index
        mov bl, [esi]
        cmp bl, 0                                               ; Test1: If bl is = 0, then we won't even deal with it
        jz NotLess
        cmp bl, al                                              ; Test2: If bl{min} !< al{current lettercount}
        jnl NotLess                                     ; Test1 if 0, Test 2 < current index, pass both then true min
Less:
        mov Min, bl                                             ; Min is only a count of the least used letter, not an actual letter
        mov dx, counter
        mov arrayOffset, dx                             ; ArrayOffset is used as the actual letter. It is an offset to get the
                                                                        ;       index of alphabet array.
NotLess:
        inc esi
        inc counter
        loop L1
        
        INVOKE GetElementAtIndex, ADDR alphabet, arrayOffset ; Convert min counted letter to an actual letter.
        mov Min, bl
        ret
CalcMinLetter ENDP

;-----------------------
CalcAvgLetter PROC
;
; Takes the length of the input string
;       and divide it by the number of letters actually used.
;-----------------------
        mov eax, stringLength
        mov Avg, al
        
        mov esi, OFFSET letterCount
        mov ecx, LENGTHOF letterCount
        
        mov eax, 0
        mov counter, 0
        
L1:
        mov al, [esi]
        cmp al, 0                                       ; If the item in letterCount is zero then it was never used, so do nothing.
        jz Zero
NotZero:
        inc counter
Zero:
        inc esi
        loop L1
                                                                ; END LOOP 1

        mov al, Avg
        mov bx, counter
        div bl                                          ; Divide length of inString by total number of letters.
        
        mov ah, 0
        mov Avg, al
        ret
CalcAvgLetter ENDP

;-----------------------
GetElementAtIndex PROC USES esi ecx,
        pArray: PTR BYTE,
        myWord: WORD
;
; Returns an element of an array at the specified index
; Recieves: pArray = byte array, pByte = byte
; Returns: BL = Array element at index
;-----------------------
        mov esi, pArray
        add si, myWord
        mov bl, [esi]
        ret
GetElementAtIndex ENDP

;-----------------------
OutputMaxMinAvg PROC
;
; Prints the output of Min, Max and Avg to the user.
;-----------------------
        mov edx, OFFSET strMax
        call WriteString
        mov al, Max
        call WriteChar
        call Crlf
        
        mov edx, OFFSET strMin
        call WriteString
        mov al, Min
        call WriteChar
        call Crlf
        
        mov edx, OFFSET strAvg
        call WriteString
        mov al, Avg
        call WriteDec
        call Crlf
        ret
OutputMaxMinAvg ENDP
END main
