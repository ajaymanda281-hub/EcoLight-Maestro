#ifndef _DEFINES_H
#define _DEFINES_H

#define SETBIT(WORD,BIT)      WORD |= (1<<BIT)
#define CLRBIT(WORD,BIT)      WORD &= ~(1<<BIT)

#define SSETBIT(WORD,BIT)     WORD = (1<<BIT)
#define SCLRBIT(WORD,BIT)     WORD = (1<<BIT)

#define READBIT(WORD,BIT)     ((WORD>>BIT)&1)

#define WRITEBYTE(WORD,POS,DATA) \
WORD=((WORD)&~(0xFF<<(POS)))|((DATA)<<(POS))

#define WRITENIBBLE(WORD,POS,DATA) \
WORD=((WORD)&~(0xF<<(POS)))|((DATA)<<(POS))

#define READNIBBLE(WORD,POS) (((WORD)>>(POS))&0xF)

#endif