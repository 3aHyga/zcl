	.386p
	model flat

PUBLIC	_NaN
PUBLIC	_Inf
PUBLIC	_NInf
PUBLIC	_MinSingle
PUBLIC	_MaxSingle
PUBLIC	_MinDouble
PUBLIC	_MaxDouble
PUBLIC	_MinExtended
PUBLIC	_MaxExtended
PUBLIC	_MinComp
PUBLIC	_MaxComp

_DATA	segment dword public use32 'DATA'
_NaN	label	tbyte
	db	0,0,0,0,0,0,0,0c0h,0ffh,0ffh

_Inf	label	tbyte
	db	0,0,0,0,0,0,0,80h,0ffh,7fh

_NInf	label	tbyte
	db	0,0,0,0,0,0,0,80h,0ffh,0ffh

_MinSingle	label	tbyte
	db	0,58h,80h,4ch,0fh,0ah,4h,89h,6ah,3fh

_MaxSingle	label	tbyte
	db	0,68h,0fdh,66h,3ch,09eh,0c9h,0ffh,7eh,40h

_MinDouble	label	tbyte
	db	0,0,0,0,0,0,0,80h,0cdh,3bh

_MaxDouble	label	tbyte
	db	0,0b0h,0dbh,0b9h,83h,89h,16h,0f2h,0feh,43h

_MinExtended	label	tbyte
	db	0,0,0,0,0,0,0,0ffh,0ffh,07fh

_MaxExtended	label	tbyte
	db	0,0,0,0,0,0,0,80h,0ffh,7fh

_MinComp	label	tbyte
	db	0,80h,91h,0d6h,0eeh,0ffh,0ffh,0ffh,3dh,0c0h

_MaxComp	label	tbyte
	db	0,80h,91h,0d6h,0eeh,0ffh,0ffh,0ffh,3dh,40h

_DATA	ends

	end

