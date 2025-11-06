for (int i = pat.length(); i < txt.length(); i++) // this loop will again take linear time.
    {
        if (isSame(freqPat, freqTxt))
        {
            return true;
        }
        freqTxt[txt[i]]++; // this is rolling function which is constant in time 
        freqTxt[txt[i - pat.length()]]--; // simply remove last and add new one;
    }