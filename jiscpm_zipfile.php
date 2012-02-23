<?php

/**
 * @file
 * Official ZIP file format: http://www.pkware.com/appnote.txt.
 */

class Zipfile {
    // Array to store compressed data.
    $datasec = array();
    // Central directory.
    $ctrldir = array();
    // End of central directory record.
    $eofctrldir = "\x50\x4b\x05\x06\x00\x00\x00\x00";
    $oldoffset = 0;
  /**
   * @function
   * Adds "directory" to archive - do this before
   * putting any files in directory!
   * $name - name of directory... like this: "path/"
   * ...then you can add files using jiscpmaddfile with names like
   * "path/file.txt".
   */
  function jiscpmadddir($name) {
    $name = str_replace("\\", "/", $name);
    $fr = "\x50\x4b\x03\x04";
    // Ver needed to extract.
    $fr .= "\x0a\x00";
    // General purpose bit flag.
    $fr .= "\x00\x00";
    // Compression method.
    $fr .= "\x00\x00";
    // Last mod time and date.
    $fr .= "\x00\x00\x00\x00";
    // Crc32.
    $fr .= pack("V", 0);
    // Compressed filesize.
    $fr .= pack("V", 0);
    // Uncompressed filesize.
    $fr .= pack("V", 0);
    // Length of pathname.
    $fr .= pack("v", drupal_strlen($name));
    // Extra field length.
    $fr .= pack("v", 0);
    $fr .= $name;
    // End of "local file header" segment.
    // No "file data" segment for path.
    // "Data descriptor" segment (optional but necessary if archive is not
    // served as file).
    // Crc32.
    $fr .= pack("V", $crc);
    // Compressed filesize.
    $fr .= pack("V", $c_len);
    // Uncompressed filesize.
    $fr .= pack("V", $unc_len);
    // Add this entry to array.
    $this->datasec[] = $fr;
    $new_offset = drupal_strlen(implode("", $this->datasec));
    // Ext. file attributes mirrors MS-DOS directory attr byte, detailed.
    // At http://support.microsoft.com/support/kb/articles/Q125/0/19.asp.
    // Now add to central record.
    $cdrec = "\x50\x4b\x01\x02";
    // Version made by.
    $cdrec .= "\x00\x00";
    // Version needed to extract.
    $cdrec .= "\x0a\x00";
    // Gen purpose bit flag.
    $cdrec .= "\x00\x00";
    // Compression method.
    $cdrec .= "\x00\x00";
    // Last mod time & date.
    $cdrec .= "\x00\x00\x00\x00";
    // Crc32.
    $cdrec .= pack("V", 0);
    // Compressed filesize.
    $cdrec .= pack("V", 0);
    // Uncompressed filesize.
    $cdrec .= pack("V", 0);
    // Length of filename.
    $cdrec .= pack("v", drupal_strlen($name));
    // Extra field length.
    $cdrec .= pack("v", 0);
    // File comment length.
    $cdrec .= pack("v", 0);
    // Disk number start.
    $cdrec .= pack("v", 0);
    // Internal file attributes.
    $cdrec .= pack("v", 0);
    $ext = "\x00\x00\x10\x00";
    $ext = "\xff\xff\xff\xff";
    // External file attributes  - 'directory' bit set.
    $cdrec .= pack("V", 16);
    // Relative offset of local header.
    $cdrec .= pack("V", $this->old_offset);
    $this->old_offset = $new_offset;
    $cdrec .= $name;
    // Optional extra field, file comment goes here.
    // Save to array.
    $this->ctrl_dir[] = $cdrec;
  }
  /**
   * @function
   * Adds "file" to archive
   * $data - file contents
   * $name - name of file in archive. Add path if your want.
   */
  function jiscpmaddfile($data, $name) {
    $name = str_replace("\\", "/", $name);
    $fr = "\x50\x4b\x03\x04";
    // Ver needed to extract.
    $fr .= "\x14\x00";
    // Gen purpose bit flag.
    $fr .= "\x00\x00";
    // Compression method.
    $fr .= "\x08\x00";
    // Last mod time and date.
    $fr .= "\x00\x00\x00\x00";
    $unc_len = drupal_strlen($data);
    $crc = crc32($data);
    $zdata = gzcompress($data);
    // Fix crc bug.
    $zdata = drupal_substr(drupal_substr($zdata, 0, drupal_strlen($zdata) - 4), 2);
    $c_len = drupal_strlen($zdata);
    // Crc32.
    $fr .= pack("V", $crc);
    // Compressed filesize.
    $fr .= pack("V", $c_len);
    // Uncompressed filesize.
    $fr .= pack("V", $unc_len);
    // Length of filename.
    $fr .= pack("v", drupal_strlen($name));
    // Extra field length.
    $fr .= pack("v", 0);
    $fr .= $name;
    // End of "local file header" segment.
    // "File data" segment.
    $fr .= $zdata;
    // "Data descriptor" segment (optional but
    // necessary if archive is not served as file).
    // Crc32.
    $fr .= pack("V", $crc);
    // Compressed filesize.
    $fr .= pack("V", $c_len);
    // Uncompressed filesize.
    $fr .= pack("V", $unc_len);
    // Add this entry to array.
    $this->datasec[] = $fr;
    $new_offset = drupal_strlen(implode("", $this->datasec));
    // Now add to central directory record.
    $cdrec = "\x50\x4b\x01\x02";
    // Version made by.
    $cdrec .= "\x00\x00";
    // Version needed to extract.
    $cdrec .= "\x14\x00";
    // Gen purpose bit flag.
    $cdrec .= "\x00\x00";
    // Compression method.
    $cdrec .= "\x08\x00";
    // Last mod time & date.
    $cdrec .= "\x00\x00\x00\x00";
    // Crc32.
    $cdrec .= pack("V", $crc);
    // Compressed filesize.
    $cdrec .= pack("V", $c_len);
    // Uncompressed filesize.
    $cdrec .= pack("V", $unc_len);
    // Length of filename.
    $cdrec .= pack("v", drupal_strlen($name));
    // Extra field length.
    $cdrec .= pack("v", 0);
    // File comment length.
    $cdrec .= pack("v", 0);
    // Disk number start.
    $cdrec .= pack("v", 0);
    // Internal file attributes.
    $cdrec .= pack("v", 0);
    // External file attributes - 'archive' bit set.
    $cdrec .= pack("V", 32);
    // Relative offset of local header.
    $cdrec .= pack("V", $this->old_offset);
    $this->old_offset = $new_offset;
    $cdrec .= $name;
    // Optional extra field, file comment goes here.
    // Save to central directory.
    $this->ctrl_dir[] = $cdrec;
  }
  /**
   * @function
   * Dump out file.
   */
  function jiscpmfile() {
    $data = implode("", $this->datasec);
    $ctrldir = implode("", $this->ctrl_dir);
    return
    $data .
    $ctrldir .
    $this->eof_ctrl_dir .
    // Total # of entries "on this disk".
    pack("v", sizeof($this->ctrl_dir)) .
    // Total # of entries overall.
    pack("v", sizeof($this->ctrl_dir)) .
    // Size of central dir.
    pack("V", drupal_strlen($ctrldir)) .
    // Offset to start of central dir.
    pack("V", drupal_strlen($data)) .
    // .Zip file comment length.
    "\x00\x00";
  }
}
