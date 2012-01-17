// $Id: jiscpm.js,v 1.3.4.2 2010/01/02 15:19:17 magnity Exp $

function jiscpm_empty_select(_select) {
  if(_select == undefined) return;
  $(_select).html('');
};

function jiscpm_fill_select(_select, _items, _with_all_option, _all_text) {
  var output = '';
  if(_with_all_option) {
    output += '<option value="0">' + _all_text + '</option>';
  }
  for (key in _items) {
    if (typeof _items[key] == 'string') {
      output += '<option value="' + key + '">' + _items[key] + '</option>';
    }
    else {
      output += '<optgroup label="' + key + '">' + jiscpm_fill_select(undefined, _items[key], false, _all_text) + '</optgroup>';
    }
  }
  if(_select == undefined) return output;
  $(_select).html(output);
};

function jiscpm_popup(sender, name, title, width, height, content_id, position) {
  var p_name = "jiscpm" + name + '_popup';
  var p_close = "jiscpm" + name + "_popup_close";

  var a = $(sender);
  var top = a.offset().top;
  var left = a.offset().left;

  switch (position) {
    case 'l':
      left = left-width;
    break;
    case 'lt':
      left = left - width;
      top = top - height;   
    break;
    case 't':
      left = left - Math.floor(width / 2); 
      top = top - height; 
    break;
    case 'rt':
      top = top - height; 
    break;
    case 'r':
    break;
    case 'rb':
    break;
    case 'b':
      left = left - Math.floor(width / 2); 
    break;
    case 'lb':
      left = left-width;
    break;
  }

  $("#" + p_name).remove();
  var popup = '<div class="jiscpm_popup" id="' + p_name + '">';
  popup += '<div class="jiscpm_popup_title" id="' + p_close + '">' + title + '</div>';
  popup += '<div class="jiscpm_popup_inner">';
  popup += $("#" + content_id).html();
  popup += "</div>";
  popup += "</div>";
  $("body").append(popup);
  var p = $("#" + p_name);
  p.css('position', 'absolute');
  p.css('top', top);
  p.css('left', left);
  p.css('width', width);
  p.css('height', height);
  p.show();
  $("#" + p_close).click(function(){
    $("#" + p_name).remove();
    return false;
  });
};

function jiscpm_datext_tonull(sender, date_id) {
  if (sender.value == "-1") {
    $("#" + date_id + '-day').val("-1");
    $("#" + date_id + '-month').val("-1");
    $("#" + date_id + '-year').val("-1");
  }
};
