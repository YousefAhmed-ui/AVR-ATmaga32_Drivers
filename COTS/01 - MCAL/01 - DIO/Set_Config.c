








DiO_enuErrorStatus SetPinConfig(PORT,PIN,MODE)
{

    DIO_enuErrorStatus Local_ErrorStatus = 0;
    if( PORT > 3)
    {
        Local_ErrorStatus = InvalidPortNumber ;
    }
    else if ( PIN > 7 )
    {
        Local_ErrorStatus = InvalidPinNumber ;
    }
    else
    {
        switch(PORT)
        {
            case PORTA:
            Local_Temp = DDRA
            Local_Temp &= ~( MASK << PIN*2 )                  // or what ever the config pin 2 is depends on the number of configuration pins
            Local_Temp |= ( MODE << PIN*2 )
            break;

            case PORTB:
            Local_Temp = DDRB
            Local_Temp &= ~( MASK << PIN*2 )                  // or what ever the config pin 2 is depends on the number of configuration pins
            Local_Temp |= ( MODE << PIN*2 )
            break;

            case PORTC:
            Local_Temp = DDRC
            Local_Temp &= ~( MASK << PIN*2 )                  // or what ever the config pin 2 is depends on the number of configuration pins
            Local_Temp |= ( MODE << PIN*2 )
            break;

            case PORTD:
            Local_Temp = DDRD
            Local_Temp &= ~( MASK << PIN*2 )                  // or what ever the config pin 2 is depends on the number of configuration pins
            Local_Temp |= ( MODE << PIN*2 )
            break;

            default:
                Local_ErrorStatus = NotOk;
                break;
        }
    } 
}