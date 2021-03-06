// Merlok, 2011
// people from mifare@nethemba.com, 2010
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// High frequency ISO14443A commands
//-----------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>
#include "data.h"

// mfCSetBlock work flags
#define CSETBLOCK_UID 					0x01
#define CSETBLOCK_WUPC					0x02
#define CSETBLOCK_HALT					0x04
#define CSETBLOCK_INIT_FIELD			0x08
#define CSETBLOCK_RESET_FIELD			0x10
#define CSETBLOCK_SINGLE_OPER			0x1F

extern char logHexFileName[FILE_PATH_SIZE];

extern int mfnested(uint8_t blockNo, uint8_t keyType, uint8_t * key, uint8_t trgBlockNo, uint8_t trgKeyType, uint8_t * ResultKeys, bool calibrate);
extern int mfCheckKeys (uint8_t blockNo, uint8_t keyType, bool clear_trace, uint8_t keycnt, uint8_t * keyBlock, uint64_t * key);

extern int mfEmlGetMem(uint8_t *data, int blockNum, int blocksCount);
extern int mfEmlSetMem(uint8_t *data, int blockNum, int blocksCount);

extern int mfCSetUID(uint8_t *uid, uint8_t *atqa, uint8_t *sak, uint8_t *oldUID, bool wantWipe);
extern int mfCSetBlock(uint8_t blockNo, uint8_t *data, uint8_t *uid, bool wantWipe, uint8_t params);
extern int mfCGetBlock(uint8_t blockNo, uint8_t *data, uint8_t params);

extern int mfTraceInit(uint8_t *tuid, uint8_t *atqa, uint8_t sak, bool wantSaveToEmlFile);
extern int mfTraceDecode(uint8_t *data_src, int len, bool wantSaveToEmlFile);

extern int isTraceCardEmpty(void);
extern int isBlockEmpty(int blockN);
extern int isBlockTrailer(int blockN);
extern int loadTraceCard(uint8_t *tuid);
extern int saveTraceCard(void);
extern int tryDecryptWord(uint32_t nt, uint32_t ar_enc, uint32_t at_enc, uint8_t *data, int len);
