package com.example.naocontroller;

import android.animation.ObjectAnimator;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.animation.AccelerateDecelerateInterpolator;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.cardview.widget.CardView;

import com.example.naocontroller.socket.MessageReceiver;
import com.example.naocontroller.socket.MessageSender;

import java.util.Objects;


public class NaoDescription extends AppCompatActivity {
    private final static String TAG = NaoDescription.class.getSimpleName();

    private TextView authorText, descriptionText, titleText, songText;

    private ImageView paintingView;

    private Button quizButton;

    private int paintingIndex;
    private String port;
    private String ip;


    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Bundle b = getIntent().getExtras();
        paintingIndex = b.getInt("painting");
        port = b.getString("port");
        ip = b.getString("ip");

        //ACTION BAR CUSTOMISATION\\
        getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_LAYOUT_STABLE | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN);
        getWindow().setStatusBarColor(Color.TRANSPARENT);
        Objects.requireNonNull(getSupportActionBar()).hide();
        //ACTION BAR CUSTOMISATION\\

        setContentView(R.layout.activity_nao_description);

        setupGraphics();

        Utilities.setTextsAndCardsImages(paintingIndex, getResources(), titleText, authorText, songText, descriptionText, paintingView);

    }

    private void setupGraphics() {
        titleText = findViewById(R.id.txt_painting_title);
        authorText = findViewById(R.id.txt_painting_author);
        songText = findViewById(R.id.txt_painting_song);
        descriptionText = findViewById(R.id.txt_painting_description);
        paintingView = findViewById(R.id.painting_image);

        quizButton = findViewById(R.id.btn_quiz);

        quizButton.setOnClickListener(v -> {
            MessageSender sender = new MessageSender();
            sender.execute("app_quiz" + paintingIndex + "_nao", ip, port);
        });
    }

    private void messageReceiver() {
        MessageReceiver message_Receiver = new MessageReceiver(messageReceived -> {
            Log.e(TAG, "Message received: " + messageReceived);
            finish();
        });
        message_Receiver.execute(String.valueOf(port));
    }
}
