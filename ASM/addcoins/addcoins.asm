TITLE Add Coins				(addcoins.asm)

; Name: Caleb Thompson
; Date: 18 February 2009
; Description: Add values of coins
; Class: CSC208

INCLUDE Irvine32.inc
CR = 0Dh ; Carriage return
LF = 0Ah ; Line-feed

.data
; Strings
dolr BYTE "Number of dollar coins:",CR,LF,0
hdlr BYTE "Number of half dollars:",CR,LF,0
qrtr BYTE "Number of Quarters:",CR,LF,0
dim  BYTE "Number of dimes:",CR,LF,0
nckl BYTE "Number of nickels:",CR,LF,0
penn BYTE "Number of pennies:",CR,LF,0
answ BYTE "The total value of the coins in cents:",CR,LF,0
; Number of coin, later value of coin
dollar  DWORD ?
half    DWORD ?
quarter DWORD ?
dime    DWORD ?
nickel  DWORD ?
penny   DWORD ?
; Multiplication variables
md DWORD 100
mh DWORD 50
mq DWORD 25
mm DWORD 10
mn DWORD 5

.code
main PROC

	mov  eax,lightGreen + (black * 16)	; Green on black
	call SetTextColor
	
	call Clrscr
	
	mov  edx,OFFSET dolr				; "#dollars"
	call WriteString
	call ReadInt						; Gather user input, stores in eax
	mov  dollar, eax					; Save input as dollar
	
	mov  edx,OFFSET hdlr				; "#half  dollars"
	call WriteString
	call ReadInt						; Gather user input, stores in eax
	mov  half, eax						; Save input as half
	
	mov  edx,OFFSET qrtr				; "#quarters"
	call WriteString
	call ReadInt						; Gather user input, stores in eax
	mov  quarter, eax					; Save input as quarter
	
	mov  edx,OFFSET dim					; "#dimes"
	call WriteString
	call ReadInt						; Gather user input, stores in eax
	mov  dime, eax						; Save input as dime
	
	mov  edx,OFFSET nckl				; "#nickels"
	call WriteString
	call ReadInt						; Gather user input, stores in eax
	mov  nickel, eax					; Save input as nickel
	
	mov  edx,OFFSET penn				; "#pennies"
	call WriteString
	call ReadInt						; Gather user input, stores in eax
	mov  penny, eax						; Save input as penny

	
	mov	 eax, dollar					; move number of given coin into eax
	mov  ebx, md						; move multiplication variable into ebx
	mul  ebx							; multiply eax and ebx
	mov  dollar, eax					; save product back to coin variable
	
	mov	 eax, half						; math for half dollars
	mov  ebx, mh
	mul  ebx
	mov  half, eax
	
	mov	 eax, quarter					; math for quarters			
	mov  ebx, mq
	mul  ebx
	mov  quarter, eax
	
	mov	 eax, dime						; math for dimes	
	mov  ebx, mm
	mul  ebx
	mov  dime, eax
	
	mov	 eax, nickel					; math for nickels	
	mov  ebx, mn
	mul  ebx
	mov  nickel, eax
	
	mov  eax, dollar					; move coin functions into registries
	mov  ebx, half	
	add  eax, ebx						; add them together
	mov  ebx, quarter
	add  eax, ebx
	mov  ebx, dime
	add  eax, ebx
	mov  ebx, nickel
	add  eax, ebx
	mov  ebx, penny
	add  eax, ebx

	call Crlf							; newline
	mov  edx,OFFSET answ				; "The answer"
	call WriteString
	call WriteDec						; Prints eax registry
	call Crlf	
	call Crlf
	exit
main ENDP

END main