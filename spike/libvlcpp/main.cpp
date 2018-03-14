#include<iostream>
#include<thread>
#include<vlcpp/vlc.hpp>


int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <file to play>" << std::endl;
        return 1;
    }

    auto instance = VLC::Instance(0, nullptr);
    auto media = VLC::Media(instance, argv[1], VLC::Media::FromPath);
    auto mp = VLC::MediaPlayer(media);
    mp.play();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    mp.stop();

}
