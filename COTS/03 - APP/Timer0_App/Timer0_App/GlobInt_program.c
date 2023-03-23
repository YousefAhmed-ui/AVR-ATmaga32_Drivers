/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 25/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GLobInt_interface.h"
#include "GlobInt_private.h"


void Globint_voidEnableGlobalInt(void)
{
    
    SET_BIT(SREG,I_BIT);
    
}

void Globint_voidDisableGlobalInt(void)
{
    CLR_BIT(SREG,I_BIT);
}
