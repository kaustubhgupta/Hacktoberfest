# Made by @JaniniRami07
# Warning it might show some errors when using an mp3 file, but dont worry
#just ignore them and if you need any help you can contact me pr0x07@tutanota.com.

import sys
import pygame
import librosa
import numpy as np
import matplotlib.pyplot as plt

from os import path
from librosa import display
from Modules.audio_bars import Bar_


# getting indexes by multipying the time and the frequency by the ratio
def get_decibel(target_time, freq):

    return spectrogram[int(freq * frequencies_index_ratio)][int(target_time * time_index_ratio)]


def pygame_gui(song_name):
    # initalizing pygame
    pygame.init()
    pygame.display.set_caption('{} Visualizer'.format(song_name.title()))

    infoObject = pygame.display.Info()
    screen_w = int(infoObject.current_w/2.5)
    screen_h = int(infoObject.current_w/2.5)
    screen = pygame.display.set_mode([screen_w, screen_h])

    bars = []
    frequencies = np.arange(100, 8000, 100)
    r = len(frequencies)
    width = screen_w/r

    x = (screen_w - width*r)/2
    for c in frequencies:
        bars.append(Bar_(x, 300, c, (32, 105, 224) , max_height=500, width=width))
        x += width

    # drawing bars
    t = pygame.time.get_ticks()
    getTicksLastFrame = t
    pygame.mixer.music.load(song_name)
    pygame.mixer.music.play(0)
    while True:
        t = pygame.time.get_ticks()
        deltaTime = (t - getTicksLastFrame) / 1000.0
        getTicksLastFrame = t

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pyGameWin = False

        # background color (optional):
        screen.fill((0, 0, 0))
        for b in bars:
            b.update(deltaTime, get_decibel(pygame.mixer.music.get_pos()/1000.0, b.freq))
            b.render(screen)

        pygame.display.flip()





if __name__ == '__main__':
    try:
        song_name = input('\n\n[+] Enter song name (must be in this folder): ')
    except:
        print('\nError: Exiting...')
        sys.exit()


    # getting information from the music file
    time_series, sample_rate = librosa.load(song_name)
    # getting a matrix which contains amplitude values according to frequency and time indexes
    stft = np.abs(librosa.stft(time_series, hop_length=512, n_fft=2048*4))
    # converting the matrix to decibel matrix
    spectrogram = librosa.amplitude_to_db(stft, ref=np.max)
    # getting an array of frequencies
    frequencies = librosa.core.fft_frequencies(n_fft=2048*4)

    # getting an array of time periodic
    times = librosa.core.frames_to_time(np.arange(spectrogram.shape[1]), sr=sample_rate, hop_length=512, n_fft=2048*4)
    time_index_ratio = len(times)/times[len(times) - 1]
    frequencies_index_ratio = len(frequencies)/frequencies[len(frequencies)-1]

    # plotting the spectrum using matplotlib (optional)
    #print('[+] Plotting spectrum...')
    #librosa.display.specshow(spectrogram,
    #                     y_axis='log', x_axis='time')
    #plt.title('{} Spectrum.'.format(song_name.title()))
    #plt.colorbar(format='%+2.0f dB')
    #plt.tight_layout()
    #plt.savefig('{}_plot.png'.format(song_name.title()), dpi=300, bbox_inches='tight')
    #print('Plot image saved.')
    #if path.exists(song_name):
    #    pass
    #else:
    #    print(f'[!] Cannot find {song_name}.')
    #    sys.exit()


    pygame_gui(song_name)
    pygame.quit()
