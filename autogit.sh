git add . 
if [ "$1" ]; then
	git commit -m "$1"
else
	git commit -m 'none'
fi
git push origin master || (git pull origin master && git push origin master)

