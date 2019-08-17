cd get && make all &&
(python3 get_Nowcoder_YTL.py; python3 get_HDU_YTL.py) | 
./get.exe > unsolved.md.swp && 
(rm ../unsolved.md.bak; mv ../unsolved.md ../unsolved.md.bak; mv unsolved.md.swp ../unsolved.md)
