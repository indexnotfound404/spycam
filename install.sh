# Install dependencies for SpyCam
# Author: https://github.com/thelinuxchoice/spycam


if [[ "$(id -u)" -ne 0 ]]; then
    printf "\e[1;77mPlease, run this program as root!\n\e[0m"
    exit 1
fi



printf "\e[1;77m[\e[0m\e[1;92m+\e[0m\e[1;77m] Updating and downloading Mingw-w64\n"
apt-get update;
apt-get install -y mingw-w64;

wget https://curl.haxx.se/download/curl-7.61.1.tar.gz

if [[ -e curl-7.61.1.tar.gz ]]; then

tar vzxf curl-7.61.1.tar.gz -C /opt/
else

printf "e[1;93m[!] Download Error!\e[0m\n"
exit 1
fi

if [[ -d /opt/curl-7.61.1 ]]; then
cd /opt/curl-7.61.1;
./configure --host=i686-w64-mingw32 --build=i686-pc-linux-gnu --prefix=/usr/i686-w64-mingw32/ --enable-static --disable-shared;
make && make install;
else
printf "e[1;93m[!] Error! Check \"tar\" command.\e[0m\n"
exit 1
fi
printf "\e[1;77m[\e[0m\e[1;92m+\e[0m\e[1;77m] Configuring PHP (php.ini)\n"
sed -i -e 's+upload_max_filesize = 2M+upload_max_filesize = 20M+g' $(php -i | grep -i "loaded configuration file" | cut -d ">" -f2)
