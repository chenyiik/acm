git add . 
if [ "$1" ]; then
	git commit -m "$1"
else
	git commit -m 'none'
fi
git push origin2 master || (git pull origin2 master && git push origin2 master)

