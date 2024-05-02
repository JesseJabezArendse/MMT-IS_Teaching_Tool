function blkStruct = slblocks
% This function specifies that the library 'mttlib'
% should appear in the Library Browser with the 
% name 'MTT Library'

    Browser.Library = 'mttlib';
    % 'mttlib' is the name of the library

    Browser.Name = 'MTT Library';
    % 'MTT Library' is the library name that appears
    % in the Library Browser

    blkStruct.Browser = Browser;
    