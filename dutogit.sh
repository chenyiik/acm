git add .
git commit -m 'no response'

edu=$(git remote -v | grep '110\.64\.92\.214.*push' | awk '{print $1}')
com=$(git remote -v | grep '251y3g3220\.qicp\.vip.*push' | awk '{print $1}')
github=$(git remote -v | grep 'github\.com.*push' | awk '{print $1}')

ping 110.64.92.214 -c 1
if [ $? == 0 ]; then
	git pull $edu master
	git push $edu master
else
	git pull $com master
	git push $com master
fi

git push $github master
