google-chrome $(grep 'url' *.url | awk -F'=' '{print $2})
