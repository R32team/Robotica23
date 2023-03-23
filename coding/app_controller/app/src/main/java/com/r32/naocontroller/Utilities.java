package com.r32.naocontroller;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Typeface;
import android.opengl.Matrix;
import android.text.SpannableStringBuilder;
import android.text.Spanned;
import android.text.style.ForegroundColorSpan;
import android.text.style.RelativeSizeSpan;
import android.text.style.StyleSpan;
import android.util.DisplayMetrics;
import android.util.TypedValue;
import android.widget.ImageView;
import android.widget.TextView;

public class Utilities {
    private final static String TAG = Utilities.class.getSimpleName();

    private Utilities() {}

    static public void setTexts(int paintingIndex, TextView titleText, TextView locationText) {
        switch (paintingIndex) {
            case 1:
                titleText.setText(R.string.title_painting_1);
                locationText.setText(R.string.location_painting_1);
                break;
            case 2:
                titleText.setText(R.string.title_painting_2);
                locationText.setText(R.string.location_painting_2);
                break;
            case 3:
                titleText.setText(R.string.title_painting_3);
                locationText.setText(R.string.location_painting_3);
                break;
            case 4:
                titleText.setText(R.string.title_painting_4);
                locationText.setText(R.string.location_painting_4);
                break;
            case 5:
                titleText.setText(R.string.title_painting_5);
                locationText.setText(R.string.location_painting_5);
                break;
            case 6:
                titleText.setText(R.string.title_painting_6);
                locationText.setText(R.string.location_painting_6);
                break;
            case 7:
                titleText.setText(R.string.title_painting_7);
                locationText.setText(R.string.location_painting_7);
                break;
            case 8:
                titleText.setText(R.string.title_painting_8);
                locationText.setText(R.string.location_painting_8);
                break;
            case 9:
                titleText.setText(R.string.title_painting_9);
                locationText.setText(R.string.location_painting_9);
                break;
            case 10:
                titleText.setText(R.string.title_painting_10);
                locationText.setText(R.string.location_painting_10);
                break;
        }
    }

    static public void setTextsAndCardsImages (
            int paintingIndex,
            Resources resources,
            TextView titleText,
            TextView authorText,
            TextView songText,
            TextView descriptionText,
            ImageView paintingView) {
        switch (paintingIndex) {
            case 1:
                titleText.setText(R.string.title_painting_1);
                authorText.setText(R.string.location_painting_1);
                songText.setText(R.string.song_painting_1);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_1);
                break;
            case 2:
                titleText.setText(R.string.title_painting_2);
                authorText.setText(R.string.location_painting_2);
                songText.setText(R.string.song_painting_2);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_2);
                break;
            case 3:
                titleText.setText(R.string.title_painting_3);
                authorText.setText(R.string.location_painting_3);
                songText.setText(R.string.song_painting_3);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_3);
                break;
            case 4:
                titleText.setText(R.string.title_painting_4);
                authorText.setText(R.string.location_painting_4);
                songText.setText(R.string.song_painting_4);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_4);
                break;
            case 5:
                titleText.setText(R.string.title_painting_5);
                authorText.setText(R.string.location_painting_5);
                songText.setText(R.string.song_painting_5);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_5);
                break;
            case 6:
                titleText.setText(R.string.title_painting_6);
                authorText.setText(R.string.location_painting_6);
                songText.setText(R.string.song_painting_6);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_6);
                break;
            case 7:
                titleText.setText(R.string.title_painting_7);
                authorText.setText(R.string.location_painting_7);
                songText.setText(R.string.song_painting_7);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_7);
                break;
            case 8:
                titleText.setText(R.string.title_painting_8);
                authorText.setText(R.string.location_painting_8);
                songText.setText(R.string.song_painting_8);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_8);
                break;
            case 9:
                titleText.setText(R.string.title_painting_9);
                authorText.setText(R.string.location_painting_9);
                songText.setText(R.string.song_painting_9);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_9);
                break;
            case 10:
                titleText.setText(R.string.title_painting_10);
                authorText.setText(R.string.location_painting_10);
                songText.setText(R.string.song_painting_10);
                descriptionText.setText(getDetailsString(paintingIndex, resources));
                paintingView.setImageResource(R.drawable.painting_10);
                break;
        }
    }

    static private SpannableStringBuilder getDetailsString(int paintingIndex, Resources resources) {
        String string;
        int redColor = resources.getColor(R.color.main_color);
        int whiteColor = resources.getColor(R.color.white);

        switch (paintingIndex) {
            case 1:
                string = resources.getString(R.string.description_painting_1);
                return formatString(string, redColor, whiteColor);
            case 2:
                string = resources.getString(R.string.description_painting_2);
                return formatString(string, redColor, whiteColor);
            case 3:
                string = resources.getString(R.string.description_painting_3);
                return formatString(string, redColor, whiteColor);
            case 4:
                string = resources.getString(R.string.description_painting_4);
                return formatString(string, redColor, whiteColor);
            case 5:
                string = resources.getString(R.string.description_painting_5);
                return formatString(string, redColor, whiteColor);
            case 6:
                string = resources.getString(R.string.description_painting_6);
                return formatString(string, redColor, whiteColor);
            case 7:
                string = resources.getString(R.string.description_painting_7);
                return formatString(string, redColor, whiteColor);
            case 8:
                string = resources.getString(R.string.description_painting_8);
                return formatString(string, redColor, whiteColor);
            case 9:
                string = resources.getString(R.string.description_painting_9);
                return formatString(string, redColor, whiteColor);
            case 10:
                string = resources.getString(R.string.description_painting_10);
                return formatString(string, redColor, whiteColor);
            default:
                return new SpannableStringBuilder();
        }
    }

    static private SpannableStringBuilder formatString (String string, int redColor, int whiteColor) {
        SpannableStringBuilder stringBuilder = new SpannableStringBuilder();
        String[] paragraphs;

        paragraphs = string.split("\\*");

        int index = 0;
        String paragraph;
        for (int i = 0; i < paragraphs.length; i ++) {
            if (paragraphs[i].equals("")) {continue;}
            paragraph = paragraphs[i];
            stringBuilder.append(paragraph);
            if (i%2 == 0) {
                stringBuilder.setSpan(new ForegroundColorSpan(whiteColor), index, index + paragraph.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
                stringBuilder.setSpan(new StyleSpan(Typeface.NORMAL), index, index + paragraph.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
                stringBuilder.setSpan(new RelativeSizeSpan(1f), index, index + paragraph.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
            } else {
                stringBuilder.setSpan(new ForegroundColorSpan(redColor), index, index + paragraph.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
                stringBuilder.setSpan(new StyleSpan(Typeface.BOLD), index, index + paragraph.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
                stringBuilder.setSpan(new RelativeSizeSpan(1.5f), index, index + paragraph.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
            }
            index += paragraph.length();
        }

        return stringBuilder;
    }

    static public int getPaintingIndexFromTitle(String paintingTitle) {
        switch(paintingTitle) {
            case "L'ARRIVO DELLE ANIME":
                return 1;
            case "MANFREDI":
                return 2;
            case "LA SCALATA":
                return 3;
            case "I MORTI DI MORTE VIOLENTA":
                return 4;
            case "SORDELLO E VIRGILIO":
                return 5;
            case "LA VALLETTA DEI PRINCIPI":
                return 6;
            case "LA CACCIATA DEL SERPENTE":
                return 7;
            case "LA PORTA DEL PURGATORIO":
                return 8;
            case "I BASSORILIEVI":
                return 9;
            case "I SUPERBI":
                return 10;
            default:
                return 0;
        }
    }



    static public float[] calculateWorldToCameraMatrix(float[] modelmtx, float[] viewmtx, float[] prjmtx) {
        float scaleFactor = 1.0f;
        float[] scaleMatrix = new float[16];
        float[] modelXscale = new float[16];
        float[] viewXmodelXscale = new float[16];
        float[] world2screenMatrix = new float[16];

        Matrix.setIdentityM(scaleMatrix, 0);
        scaleMatrix[0] = scaleFactor;
        scaleMatrix[5] = scaleFactor;
        scaleMatrix[10] = scaleFactor;

        Matrix.multiplyMM(modelXscale, 0, modelmtx, 0, scaleMatrix, 0);
        Matrix.multiplyMM(viewXmodelXscale, 0, viewmtx, 0, modelXscale, 0);
        Matrix.multiplyMM(world2screenMatrix, 0, prjmtx, 0, viewXmodelXscale, 0);

        return world2screenMatrix;
    }

    static public double[] world2Screen(int screenWidth, int screenHeight, float[] world2cameraMatrix) {
        float[] origin = {0f, 0f, 0f, 1f};
        float[] ndcCoord = new float[4];
        Matrix.multiplyMV(ndcCoord, 0,  world2cameraMatrix, 0,  origin, 0);

        ndcCoord[0] = ndcCoord[0]/ndcCoord[3];
        ndcCoord[1] = ndcCoord[1]/ndcCoord[3];

        double[] pos_2d = new double[]{0,0};
        pos_2d[0] = screenWidth  * ((ndcCoord[0] + 1.0)/2.0);
        pos_2d[1] = screenHeight * (( 1.0 - ndcCoord[1])/2.0);

        return pos_2d;
    }

    static public boolean isInScreen(float[] modelmtx, float[] viewmtx, float[] projmtx, DisplayMetrics displayMetrics) {
        int height = displayMetrics.heightPixels;
        int width = displayMetrics.widthPixels;

        float[] anchorMatrix = new float[16];
        float[] world2screenMatrix = Utilities.calculateWorldToCameraMatrix(modelmtx, viewmtx, projmtx);
        double[] anchor_2d = Utilities.world2Screen(width, height, world2screenMatrix);

        return 0 < anchor_2d[0] && anchor_2d[0] < width
                && 0 < anchor_2d[1] && anchor_2d[1] < height;
    }

    static public float getDP(Context context, float dp) {
        return TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp, context.getResources().getDisplayMetrics());
    }
}
