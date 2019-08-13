cd get && make all &&
echo -e '\nFucking nowcoder star...' &&
python3 get_Nowcoder_YTL.py | ./nowcoder.exe > unsolved.md.swp &&
echo -e 'Nowcoder fucking complete!\n\nFucking HDU star...' &&
python3 get_HDU_YTL.py | ./hdu.exe >> unsolved.md.swp &&
echo 'HDU fucking complete!' &&
(rm ../unsolved.md; mv unsolved.md.swp ../unsolved.md)
