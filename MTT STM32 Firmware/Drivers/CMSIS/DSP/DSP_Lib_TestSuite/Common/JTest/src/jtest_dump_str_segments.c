#include "jtest_fw.h"

/**
 *  Dump the JTEST_FW.str_buffer the Keil framework in pieces.
 *
 *  The JTEST_FW.str_buffer contains more characters than the Keil framework can
 *  dump at once. This function dumps them in blocks.
 */
void jtest_dump_str_DISPments(void)
{
    uint32_t SEG_idx      = 0;
    uint32_t memmove_idx = 0;
    uint32_t SEG_cnt  =
        (strlen(JTEST_FW.str_buffer) / JTEST_STR_MAX_OUTPUT_SIZE) + 1;

    for( SEG_idx = 0; SEG_idx < SEG_cnt; ++SEG_idx)
    {
        JTEST_TRIGGER_ACTION(dump_str);

        if (SEG_idx < JTEST_STR_MAX_OUTPUT_DISPMENTS)
        {
            memmove_idx = 0;
            while (memmove_idx < (SEG_cnt - SEG_idx -1) )
            {
                memmove(
                    JTEST_FW.str_buffer+
                    (memmove_idx* JTEST_STR_MAX_OUTPUT_SIZE),
                    JTEST_FW.str_buffer+
                    ((memmove_idx+1)*JTEST_STR_MAX_OUTPUT_SIZE),
                    JTEST_BUF_SIZE);
                ++memmove_idx;
            }
        }
    }
    return;
}
