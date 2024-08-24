
int level = 0;
void Timer0_Routine(void) interrupt 1
{

      if (T0Count == 0)
    {
            T0Count = SPEEDVALUE;
            if (level = 0)
        {
                  level = 1;

               
        }
            else
        {
                  level = 0;
               
        }
            if (degCount > 0)
        {
                  degCount--
      PWM = level;
               
        }
            else
        {
                  PWM = 0;
               
        }
         
    }
      else
    {
            T0Count--;
         
    }
}