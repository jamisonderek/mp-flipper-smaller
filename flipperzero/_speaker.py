'''
Python script for notes generation

# coding: utf-8
# Python script for notes generation

from typing import List

note_names: List = ['C', 'CS', 'D', 'DS', 'E', 'F', 'FS', 'G', 'GS', 'A', 'AS', 'B']

for octave in range(9):
    for name in note_names:
        print("SPEAKER_NOTE_%s%s: float" % (name, octave))
        print('\'\'\'')
        print('The musical note %s\\ :sub:`0` as frequency in `Hz`.\n' % (name if len(name) == 1 else (name[0]+'#')))
        print('.. versionadded:: 1.2.0')
        print('\'\'\'\n')
'''

SPEAKER_VOLUME_MIN: float
'''
The minimal volume value.

.. versionadded:: 1.2.0
'''

SPEAKER_VOLUME_MAX: float
'''
The maximum volume value.

.. versionadded:: 1.2.0
'''

def speaker_start(frequency: float, volume: float) -> bool:
    '''
    Output a steady tone of a defined frequency and volume on the Flipper's speaker.
    This is a non-blocking operation. The tone will continue until you call :func:`speaker_stop`.
    The ``volume`` parameter accepts values from :py:const:`SPEAKER_VOLUME_MIN` (silent) up to :py:const:`SPEAKER_VOLUME_MAX` (very loud).

    :param frequency: The frequency to play in `Hz <https://en.wikipedia.org/wiki/Hertz>`_.
    :param volume: The volume to use.
    :returns: :const:`True` if the speaker was acquired.

    .. versionadded:: 1.0.0

    .. code-block::
        
        import flipperzero as f0
        
        f0.speaker_start(50.0, 0.8)
    '''
    pass

def speaker_set_volume(volume: float) -> bool:
    '''
    Set the speaker's volume while playing a tone. This is a non-blocking operation.
    The tone will continue until you call :func:`speaker_stop`.
    The ``volume`` parameter accepts values from 0.0 (silent) up to 1.0 (very loud).
    
    :param volume: The volume to use.
    :returns: :const:`True` if the speaker was acquired.

    .. versionadded:: 1.0.0

    This function can be used to play `nice` sounds:

    .. code-block::

        import time
        import flipperzero as f0
        
        volume = 0.8

        f0.speaker_start(100.0, volume)

        for _ in range(0, 150):
            volume *= 0.9945679

            f0.speaker_set_volume(volume)

            time.sleep_ms(1)
        
        f0.speaker_stop()
    '''
    pass

def speaker_stop() -> bool:
    '''
    Stop the speaker output.

    :returns: :const:`True` if the speaker was successfully released.

    .. versionadded:: 1.0.0
    '''
    pass
