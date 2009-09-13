/*double parse(char** tokens, int start, int finish)
{
   double output = 0;
   double a = 0.0, b = 0.0;
   while(1)
   {
      if(strcmp(tokens[start], "+") == 0)
      {
         return temp + parse(tokens, start + 1, finish);
      }
      else if(strcmp(tokens[start], "-") == 0)
      {
         return temp - parse(tokens, start + 1, finish);
      }
      else if(strcmp(tokens[start], "*") == 0)
      {
         return temp * parse(tokens, start + 1, finish);
      }
      else if(strcmp(tokens[start], "/") == 0)
      {
         return temp / parse(tokens, start + 1, finish);
      }
      else if(strcmp(tokens[start], "(") == 0)
      {
         int parenCount = 0;
         int i = start;
         for(; i < finish; i++)
         {
            if(strcmp(tokens[i], "(") == 0)
            {
               parenCount++;
            }
            else if(strcmp(tokens[i], ")") == 0)
            {
               parenCount--;
            }
            if(parenCount == 0 && i != start)
            {
               break;
            }
         }
         
         return parse(subExpression, start + 1, i);
      }
      else
      {
         temp = (float)atof(tokens[start]);
      }
   }
}*/